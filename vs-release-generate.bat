SET BUILDDIR=build-release
mkdir %BUILDDIR%
cd %BUILDDIR%
del CMakeCache.txt
cd ..
cmake -B %BUILDDIR% -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=%VCPKG_CMAKE_FILE% -DBUILD_TESTS=OFF
pause%
