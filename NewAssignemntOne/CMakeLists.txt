CMAKE_minimus_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGs "${CMAKE_CXX_FLAGS} -std=++14")

project(mazer)

add_executable(
	mazer
	mazeBuilder.cpp
	mazeLoader.cpp
)





