cmake_minimum_required(VERSION 3.23)
set(project "pacman")
project(${project})
set(CMAKE_CXX_STANDARD 17)
set(${project}_SOURCES
        main.cpp)

add_executable(${project}
        ${${project}_SOURCES})

target_link_libraries(${project})