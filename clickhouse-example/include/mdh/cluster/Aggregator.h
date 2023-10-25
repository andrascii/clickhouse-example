#pragma once
#include <chrono>
#include <deque>
#include <mdh/cluster/Collector.h>
#include <observable/observe.hpp>

namespace mdh::cluster {
namespace detail {
template <typename T, typename Collector, typename Duration = std::chrono::duration<double, std::milli>>
class Aggregator {

  using CollectorPtr = std::shared_ptr<Collector>;
  using Any = typename Collector::Any;
  using Batch = typename Collector::Batch;

public:
  template <typename AnyDuration>
  Aggregator(CollectorPtr collector, AnyDuration duration, std::size_t max_size);

  void Start();

  void Write(const std::vector<T> &vector);

  void Stop();

  void StartFlushing();

  void StopFlushing();

private:
  CollectorPtr collector_;
  Duration duration_;
  std::size_t max_size_;
  std::mutex monitor_;
  std::condition_variable flush_;
  std::jthread flush_thread_;
  std::atomic_bool do_flushing_;
  std::deque<T> queue_;
  bool Flush();
};
} // namespace detail

template <typename... Ts>
class Aggregator : public std::enable_shared_from_this<Aggregator<Ts...>> {

  friend class Collector<Ts...>;

  using Collector = Collector<Ts...>;

  using CollectorPtr = std::shared_ptr<Collector>;

  template <typename T>
  using BaseAggregator = detail::Aggregator<T, Collector>;

  template <typename T>
  using BaseAggregatorPtr = std::shared_ptr<BaseAggregator<T>>;

public:
  using Any = typename Collector::Any;
  using Batch = typename Collector::Batch;

  template <typename AnyDuration>
  explicit Aggregator(CollectorPtr collector, AnyDuration duration, std::size_t max_size);

  void Start();

  void Write(const Batch &batch);

  void Stop();

private:
  CollectorPtr collector_;
  std::tuple<BaseAggregatorPtr<Ts>...> aggregators_;
  std::mutex monitor_;
  bool started_;

  template <typename T>
  void Write(const std::vector<T> &v);

  void StartFlushing();

  void StopFlushing();
};

template <typename... Ts>
template <typename AnyDuration>
Aggregator<Ts...>::Aggregator(CollectorPtr collector, AnyDuration duration, std::size_t max_size)
    : collector_{std::move(collector)}
    , started_{false} {
  aggregators_ = std::make_tuple(std::make_shared<BaseAggregator<Ts>>(collector_, duration, max_size)...);
  collector_->OnLeader([this] { return this->StartFlushing(); });
  collector_->OnFollower([this] { return this->StopFlushing(); });
}

template <typename... Ts>
void Aggregator<Ts...>::Start() {
  std::unique_lock _{monitor_};
  if (started_) {
    return;
  }
  std::apply([](auto &&...aggregator) { ((void)aggregator->Start(), ...); }, aggregators_);
  started_ = true;
}

template <typename... Ts>
void Aggregator<Ts...>::Write(const Batch &batch) {
  std::tuple<std::vector<Ts>...> sorted_batches;
  for (const auto &object : batch) {
    std::visit(
      [&sorted_batches]<typename T>(T &&message) {
        using T0 = std::decay_t<T>;
        auto &vector = std::get<std::vector<T0>>(sorted_batches);
        vector.emplace_back(std::forward<T>(message));
      },
      object
    );
  }
  std::unique_lock _{monitor_};
  if (!started_) {
    LOG_FATAL("attempted to write to stopped aggregator");
    _Exit(EXIT_FAILURE);
  }
  std::apply(
    [this]<typename... T>(T &&...vec) { (this->template Write<typename std::decay_t<T>::value_type>(vec), ...); },
    sorted_batches
  );
}

template <typename... Ts>
void Aggregator<Ts...>::Stop() {
  std::unique_lock _{monitor_};
  if (!started_) {
    return;
  }
  std::apply([](auto &&...aggregator) { ((void)aggregator->Stop(), ...); }, aggregators_);
  started_ = false;
}

template <typename... Ts>
template <typename T>
void Aggregator<Ts...>::Write(const std::vector<T> &v) {
  return std::get<BaseAggregatorPtr<T>>(aggregators_)->Write(v);
}

template <typename... Ts>
void Aggregator<Ts...>::StartFlushing() {
  std::unique_lock _{monitor_};
  LOG_INFO("starting flushing aggregation queues");
  std::apply([](auto &&...aggregator) { ((void)aggregator->StartFlushing(), ...); }, aggregators_);
}


template <typename... Ts>
void Aggregator<Ts...>::StopFlushing() {
  std::unique_lock _{monitor_};
  LOG_INFO("stopping flushing aggregation queues");
  std::apply([](auto &&...aggregator) { ((void)aggregator->StopFlushing(), ...); }, aggregators_);
}

namespace detail {
template <typename T, typename Collector, typename Duration>
template <typename AnyDuration>
Aggregator<T, Collector, Duration>::Aggregator(CollectorPtr collector, AnyDuration duration, const std::size_t max_size)
    : collector_{std::move(collector)}
    , duration_{std::chrono::duration_cast<Duration>(duration)}
    , max_size_{max_size}
    , do_flushing_{false} {
}

template <typename T, typename Collector, typename Duration>
void Aggregator<T, Collector, Duration>::Start() {
  flush_thread_ = std::jthread{[this](const std::stop_token &stop_token) {
    while (!stop_token.stop_requested()) {
      std::unique_lock lock{monitor_};
      auto predicate = [this, &stop_token] { return (!queue_.empty() && do_flushing_) || stop_token.stop_requested(); };
      // if we do flushing
      if (do_flushing_) {
        // wait with timeout (1s) till queue is empty
        LOG_INFO("waiting for a flush cycle for {:s}", typeid(T).name());
        flush_.wait_for(lock, duration_, predicate);
      } else {
        LOG_INFO("waiting to become a leader for {:s}", typeid(T).name());
        // we don't do flushing, no need to cycle
        flush_.wait(lock, predicate);
      }
      if (!Flush()) {
        LOG_INFO("i failed to send data to the cluster, so i sleep for {}", duration_);
        std::this_thread::sleep_for(duration_);
      }
    }
  }};
}

template <typename T, typename Collector, typename Duration>
void Aggregator<T, Collector, Duration>::Write(const std::vector<T> &vector) {
  std::unique_lock _{monitor_};
  std::copy(begin(vector), end(vector), std::back_inserter(queue_));
  if (queue_.size() >= max_size_) {
    flush_.notify_all();
  }
}

template <typename T, typename Collector, typename Duration>
void Aggregator<T, Collector, Duration>::Stop() {
  // force flush
  flush_.notify_all();
  // stop flushing thread
  flush_thread_.request_stop();
  flush_thread_.join();
}

template <typename T, typename Collector, typename Duration>
bool Aggregator<T, Collector, Duration>::Flush() {
  Batch batch;
  auto success_flush = false;
  LOG_INFO("copying {:d} message(s) to batch", queue_.size());
  std::copy(begin(queue_), end(queue_), std::back_inserter(batch));
  const auto batch_size = batch.size();
  LOG_INFO("writing batch of {:d} message(s)", batch_size);
  if (collector_->Write(batch)) {
    queue_.clear();
    LOG_INFO("successful write of {:d} message(s)", batch_size);
    success_flush = true;
  } else {
    LOG_ERROR("unsuccessful write of {:d} message(s)", batch_size);
    success_flush = false;
  }
  return success_flush;
}

template <typename T, typename Collector, typename Duration>
void Aggregator<T, Collector, Duration>::StartFlushing() {
  std::unique_lock _{monitor_};
  do_flushing_ = true;
  flush_.notify_all();
  LOG_INFO("*** start flushing {:s} ***", typeid(T).name());
}

template <typename T, typename Collector, typename Duration>
void Aggregator<T, Collector, Duration>::StopFlushing() {
  std::unique_lock _{monitor_};
  do_flushing_ = false;
  flush_.notify_all();
  LOG_INFO("*** stopping flushing {:s} ***", typeid(T).name());
}
} // namespace detail
} // namespace mdh::cluster
