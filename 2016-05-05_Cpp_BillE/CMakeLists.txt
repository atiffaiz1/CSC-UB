cmake_minimum_required(VERSION 3.5)
project(c___intro_presentation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp basic_types.cpp derived_types.cpp namespaces.cpp functions.cpp classes.cpp advanced.cpp)
add_executable(c___intro_presentation ${SOURCE_FILES})