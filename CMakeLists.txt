cmake_minimum_required(VERSION 3.8)
project(cpp_nanotekspice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -std=c++17")

include_directories(include)

set(SOURCE_FILES
        src/Circuit.cpp
        src/Circuit.hpp
        src/componentList.cpp
        src/components/AComponent.cpp
        src/components/AComponent.hpp
        src/components/ComponentFF.cpp
        src/components/ComponentFF.hpp
        src/components/Components4000/Component4008.cpp
        src/components/Components4000/Component4008.hpp
        src/components/Components4000/Component4013.cpp
        src/components/Components4000/Component4013.hpp
        src/components/Components4000/Component4017.cpp
        src/components/Components4000/Component4017.hpp
        src/components/Components4000/Component4040.cpp
        src/components/Components4000/Component4040.hpp
        src/components/Components4000/Component4069.cpp
        src/components/Components4000/Component4069.hpp
        src/components/Components4000/Component4094.cpp
        src/components/Components4000/Component4094.hpp
        src/components/Components4000/Component4094.hpp
        src/components/Components4000/Component4503.cpp
        src/components/Components4000/Component4503.hpp
        src/components/Components4000/Component4514.cpp
        src/components/Components4000/Component4514.hpp
        src/components/Components4000/Component4Gate.cpp
        src/components/Components4000/Component4Gate.hpp
        src/components/gates/AGate.cpp
        src/components/gates/AGate.hpp
        src/components/gates/ComponentAND.cpp
        src/components/gates/ComponentAND.hpp
        src/components/gates/ComponentNAND.cpp
        src/components/gates/ComponentNAND.hpp
        src/components/gates/ComponentNOR.cpp
        src/components/gates/ComponentNOR.hpp
        src/components/gates/ComponentNOT.cpp
        src/components/gates/ComponentNOT.hpp
        src/components/gates/ComponentOR.cpp
        src/components/gates/ComponentOR.hpp
        src/components/gates/ComponentXNOR.cpp
        src/components/gates/ComponentXNOR.hpp
        src/components/gates/ComponentXOR.cpp
        src/components/gates/ComponentXOR.hpp
        src/components/IComponent.hpp
        src/components/singleComponents/ComponentFalse.cpp
        src/components/singleComponents/ComponentFalse.hpp
        src/components/singleComponents/ComponentTrue.cpp
        src/components/singleComponents/ComponentTrue.hpp
        src/exception/NtsException.cpp
        src/exception/NtsException.hpp
        src/InGame.cpp
        src/InGame.hpp
        src/operator/TristateOperator.cpp
        src/other/ClockManager.cpp
        src/other/ClockManager.hpp
        src/Parser.cpp
        src/Parser.hpp
        src/pin/APin.cpp
        src/pin/APin.hpp
        src/pin/APinComponent.cpp
        src/pin/APinComponent.hpp
        src/pin/APinExt.cpp
        src/pin/APinExt.hpp
        src/pin/IPin.hpp
        src/pin/PinComponentIn.cpp
        src/pin/PinComponentIn.hpp
        src/pin/PinComponentOut.cpp
        src/pin/PinComponentOut.hpp
        src/pin/PinInput.cpp
        src/pin/PinInput.hpp
        src/pin/PinOutput.cpp
        src/pin/PinOutput.hpp)


add_executable(nanotekspice
        src/main.cpp
        ${SOURCE_FILES})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_executable(helloworld WIN32 src/main.cpp ${SOURCE_FILE})

target_link_libraries(helloworld Qt5::Widgets)
