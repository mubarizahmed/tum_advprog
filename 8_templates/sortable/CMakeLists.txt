cmake_minimum_required(VERSION 3.0.0)
project(Sortable VERSION 0.1.0
        LANGUAGES CXX)

add_executable(sortable sortable.cpp)
target_compile_features(sortable PRIVATE cxx_std_20)