cmake_minimum_required(VERSION 3.10)

project(JNeuralNetwork VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(GOOGLETEST_DIR "${CMAKE_SOURCE_DIR}/external/googletest")

add_subdirectory(${GOOGLETEST_DIR} ${CMAKE_BINARY_DIR}/googletest)

include_directories(${GOOGLETEST_DIR}/googletest/include ${GOOGLETEST_DIR}/googlemock/include)

add_executable(
    JNeuralNetwork 
    "src/Main.cpp" 
    "src/Neuron/Neuron.h" 
    "src/Neuron/Neuron.cpp" 
    "src/Layer/Layer.h" 
    "src/Layer/Layer.cpp" 
    "src/Math/Matrix.h" 
    "src/Math/Matrix.cpp" 
    "src/Utils/RandomUtil.h" 
    "src/Utils/RandomUtil.cpp" 
    "src/Common/Assert.h"
    "src/Network/NeuralNetwork.h" 
    "src/Network/NeuralNetwork.cpp"
)

enable_testing()

file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(JNeuralNetworkTests ${TEST_SOURCES} "src/Math/Matrix.cpp" "src/Utils/RandomUtil.cpp" "src/Neuron/Neuron.cpp" "src/Network/NeuralNetwork.cpp")
target_link_libraries(JNeuralNetworkTests gtest gtest_main)
add_test(NAME AllTests COMMAND JNeuralNetworkTests)

