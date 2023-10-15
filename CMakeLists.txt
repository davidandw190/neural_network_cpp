cmake_minimum_required(VERSION 3.26)
project(neural_network_cpp)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(neural_network_cpp main.cpp
        Headers/GlobalConstants.hpp
        NNDrawer.cpp
        Headers/NNDrawer.hpp
        TextDrawer.cpp
        Headers/TextDrawer.hpp
        MinElement.cpp
        Headers/MinElement.hpp)

target_link_libraries(neural_network_cpp sfml-graphics)