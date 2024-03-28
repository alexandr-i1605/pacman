cmake_minimum_required(VERSION 3.23)

set(project "pacman")
project(${project})
set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCE_LIST
        src/main.cpp)

set(${project}_INCLUDE_LIST
        )

set(SFML_DIR ${CMAKE_SOURCE_DIR}/extern/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

add_executable(${project}
        ${${project}_SOURCE_LIST}
        ${${project}_INCLUDE_LIST})

target_link_libraries(pacman sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
