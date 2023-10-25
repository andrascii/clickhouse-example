#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <mdh/cluster/Clickhouse.h>

namespace mdh::cluster {
InsecureChannel::InsecureChannel(std::string host)
  : host_{std::move(host)} {
}

auto InsecureChannel::operator()() const -> std::shared_ptr<grpc::ChannelInterface> {
  grpc::ChannelArguments args;
  args.SetLoadBalancingPolicyName("round_robin");
  args.SetCompressionAlgorithm(GRPC_COMPRESS_DEFLATE);
  return CreateCustomChannel(host_, grpc::InsecureChannelCredentials(), args);
}

}
