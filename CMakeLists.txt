cmake_minimum_required(VERSION 3.11 )

project(Opengl3dProject VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(glad STATIC src/glad.c)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(SOURCES
	src/main.cpp
	)

include_directories(include)

add_executable(Opengl3dProject ${SOURCES})

target_link_libraries(Opengl3dProject glfw OpenGL::GL glad)