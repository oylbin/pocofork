cmake_minimum_required(VERSION 3.15)
project(PackageTest CXX)

#find_package(poco)
find_package(Poco REQUIRED Foundation Net Util CONFIG)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(example_lib src/examplelib.cpp)
target_link_libraries(example_lib PRIVATE Poco::Foundation Poco::Net Poco::Util)
if(NOT IOS)
    add_executable(example src/example.cpp)
    target_link_libraries(example PRIVATE example_lib Poco::Foundation Poco::Net Poco::Util)
endif()


