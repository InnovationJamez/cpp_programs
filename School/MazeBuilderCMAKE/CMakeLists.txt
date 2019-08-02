cmake_minimum_required(VERSION 2.8)
project(mazer)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS " -Wall -pedantic -std=c++14 -Wextra -g")
set(CMAKE_CXX_COMPILER "/opt/rh/devtoolset-6/root/usr/bin/g++")

add_executable(mazer
        SourceFiles/builder.cpp

		HeaderFiles/GrowingTree.h
		SourceFiles/GrowingTree.cpp
		
		HeaderFiles/MazeLoader.h
		SourceFiles/MazeLoader.cpp
		
		HeaderFiles/PrimAlgorithm.h
		SourceFiles/PrimAlgorithm.cpp
		
		HeaderFiles/RecursiveBacktrack.h
		SourceFiles/RecursiveBacktrack.cpp
        )
