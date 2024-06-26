cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_REQUIRED ON)

include(FetchContent)

set(project "pacman")
project(${project})

set(IMGUI_VERSION 1.90)

set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG "2.6.x")
FetchContent_Declare(
        imgui
        URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
)
FetchContent_Declare(
        imgui-sfml
        GIT_REPOSITORY "https://github.com/SFML/imgui-sfml.git"
        GIT_TAG "2.6.x"
)

option(SFML_BUILD_NETWORK OFF)

set(IMGUI_DIR ${CMAKE_BINARY_DIR}/_deps/imgui-src)
option(IMGUI_SFML_FIND_SFML OFF)

FetchContent_MakeAvailable(sfml imgui imgui-sfml)

file(GLOB_RECURSE SOURCE_LIST "src/*.cpp")
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${project}
        ${SOURCE_LIST})

target_link_libraries(${project}
        PUBLIC
        sfml-audio
        sfml-graphics
        sfml-window
        sfml-system
        ImGui-SFML::ImGui-SFML
)

target_include_directories(${project} PUBLIC include)
