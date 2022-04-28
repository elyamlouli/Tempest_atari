cmake_minimum_required(VERSION 3.6)

add_subdirectory(SDL)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

project(tempest LANGUAGES CXX)

set (CMAKE_CXX_STANDARD_FLAG "{CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g -std=c++2a")

add_executable (${PROJECT_NAME} ${SOURCES})
# target_sources(${PROJECT_NAME} PRIVATE tp_sdl.cpp menu.cpp game.cpp blaster.cpp utils.cpp bullet.cpp tube.cpp enemy.cpp score.cpp audio.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
