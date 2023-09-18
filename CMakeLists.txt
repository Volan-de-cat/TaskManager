cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

# Create an executable from the collected source files
add_executable(MyExecutable ${SOURCES})