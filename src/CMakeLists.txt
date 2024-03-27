cmake_minimum_required(VERSION 3.23)
set(project "pacman")
project(${project})
set(CMAKE_CXX_STANDARD 17)

add_executable(src "main.cpp")

target_link_libraries(src ${CMAKE_SOURCE_DIR}/lib/sfml-graphics.lib)
target_link_libraries(src ${CMAKE_SOURCE_DIR}/lib/sfml-audio.lib)
target_link_libraries(src ${CMAKE_SOURCE_DIR}/lib/sfml-network.lib)
target_link_libraries(src ${CMAKE_SOURCE_DIR}/lib/sfml-system.lib)
target_link_libraries(src ${CMAKE_SOURCE_DIR}/lib/sfml-window.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)