cmake_minimum_required(VERSION 3.8)
project(cpp_nanotekspice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -std=c++14")

include_directories(include)

set(SOURCE_FILES
        include/IComponent.hpp
        include/IPin.hpp
        src/pin/APin.cpp
        src/pin/APin.hpp
        src/pin/APinExt.cpp
        src/pin/APinExt.hpp
        src/pin/PinOutput.cpp
        src/pin/PinOutput.hpp
        src/pin/PinInput.cpp
        src/pin/PinInput.hpp
        src/pin/APinComponent.cpp
        src/pin/APinComponent.hpp
        src/pin/PinComponentOut.cpp
        src/pin/PinComponentOut.hpp
        src/pin/PinComponentIn.cpp
        src/pin/PinComponentIn.hpp
        include/IGate.hpp)

add_executable(nanotekspice
        src/main.cpp
        ${SOURCE_FILES})