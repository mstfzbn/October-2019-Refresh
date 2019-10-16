cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(test_cpp)

add_executable(

  testcpp
  defines.hpp
  includes.hpp
  Container.hpp
  Container.cpp
  functions.hpp
  todo.hpp
  main.cpp
)
