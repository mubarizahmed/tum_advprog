cmake_minimum_required (VERSION 3.0)
project (matVec VERSION 0.4.0 LANGUAGES CXX)

# We need to enable testing before we can define tests
enable_testing()

# Find at least version 3.3 of Eigen3
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# We can build matvec by building matvec.cpp
add_executable (matVec matVec.cpp)
# matvec needs to be linked to Eigen (which exports a CMake target called Eigen3::Eigen)
target_link_libraries (matVec Eigen3::Eigen)

target_compile_features(matVec PUBLIC cxx_std_20)

# # We also want to build a separate executable with our tests, testmatvec.
# # We have moved the test code into testmatvec.cpp
add_executable (testmatvec testmatvec.cpp)
# # # Add a test case, which simply runs testmatvec.
# # # We could have more test cases with different configurations.
add_test(NAME matrix_vector_multiplication
         COMMAND testmatvec)
target_link_libraries (testmatvec Eigen3::Eigen)
