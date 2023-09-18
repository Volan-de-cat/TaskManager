cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Collect all .cpp files in the current directory
file(GLOB SOURCES "*.cpp")

# Create an executable from the collected source files
add_executable(MyExecutable ${SOURCES})
