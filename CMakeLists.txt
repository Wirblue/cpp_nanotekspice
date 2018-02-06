cmake_minimum_required(VERSION 3.8)
project(cpp_nanotekspice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -std=c++14")

include_directories(include)

set(SOURCE_FILES
        src/main.cpp
        include/IComponent.hpp
        include/ILink.hpp
        include/IPin.hpp)

add_executable(nanotekspice ${SOURCE_FILES})