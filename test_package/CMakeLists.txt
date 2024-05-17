cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

#find_package(poco)
find_package(Poco REQUIRED Foundation Net Util CONFIG)
set(POCO_CXX_STD cxx_std_14)

add_executable(example src/example.cpp)
target_link_libraries(example PRIVATE Poco::Foundation Poco::Net Poco::Util)
target_compile_features(example PRIVATE ${POCO_CXX_STD})