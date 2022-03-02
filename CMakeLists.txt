# (1) CMake definitions, compiler flags and useful variables
cmake_minimum_required(VERSION 3.7)
project(file_systems)

add_compile_options(-Wall -Werror)

set(APP_NAME debug)
set(APP_LIB_NAME filesystemlib)

# (2) Include application build instructions
add_subdirectory(src)

# (3) include tests build instructions   
add_subdirectory(tests)