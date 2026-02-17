cmake_minimum_required(VERSION 3.0.0)
project(vec VERSION 0.1.0
        LANGUAGES CXX)
add_executable(vec main.cpp)

target_compile_features(vec PRIVATE cxx_std_17)

# TODO 5: uncomment this to use address sanitizer
# target_link_libraries(vec -fsanitize=address)
