cmake_minimum_required(VERSION 3.8)
project(cpp_nanotekspice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -std=c++17")

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
        src/components/AComponent.cpp
        src/components/AComponent.hpp
        src/components/gates/ComponentAND.cpp
        src/components/gates/ComponentAND.hpp
        src/pin/PinInput.cpp
        src/pin/PinInput.hpp
        src/operator/TristateOperator.cpp
        src/components/gates/ComponentOR.cpp
        src/components/gates/ComponentOR.hpp
        src/components/Component4Gate.cpp
        src/components/Component4Gate.hpp
        src/components/gates/ComponentNOT.cpp
        src/components/gates/ComponentNOT.hpp src/components/gates/ComponentNAND.cpp src/components/gates/ComponentNAND.hpp src/components/gates/ComponentNOR.cpp src/components/gates/ComponentNOR.hpp src/components/gates/ComponentXOR.cpp src/components/gates/ComponentXOR.hpp src/components/gates/ComponentXNOR.cpp src/components/gates/ComponentXNOR.hpp src/Circuit.cpp src/Circuit.hpp src/componentList.cpp)

add_executable(nanotekspice
        src/main.cpp
        ${SOURCE_FILES})