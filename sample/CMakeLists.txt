cmake_minimum_required(VERSION 3.15)

project(MyProject VERSION 1.0)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(some_header_only_lib INTERFACE)


add_executable(license-manager-sample main.cc)

