cmake_minimum_required(VERSION 3.8)
project(caseTrack VERSION 1.0.0 LANGUAGES CXX)
# copy data files to the build directory
file(COPY ../data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
add_executable(caseTrack caseTrack.cpp helper.cpp)
target_compile_features(caseTrack PUBLIC cxx_std_20)