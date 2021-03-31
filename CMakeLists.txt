# CMakeList.txt : CMake project for Nordic_blinky, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Nordic_blinky")

# Add source to this project's executable.
add_executable (Nordic_blinky "main.cpp" "Nordic_blinky.h")

# TODO: Add tests and install targets if needed.
