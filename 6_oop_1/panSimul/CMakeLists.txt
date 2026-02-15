cmake_minimum_required(VERSION 3.8)
project(panSimul VERSION 0.1.0 LANGUAGES CXX)
add_executable(panSimul main.cpp person.cpp)
target_compile_features(panSimul PUBLIC cxx_std_17)
