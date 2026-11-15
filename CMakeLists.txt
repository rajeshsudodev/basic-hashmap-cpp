# Minimum Version Required
cmake_minimum_required(VERSION 3.16)

# Project Information
Project(HashMap LANGUAGES CXX)

# C++ Standard Configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Executables
add_executable(op HashMap.cpp)
