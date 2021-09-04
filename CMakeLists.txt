cmake_minimum_required(VERSION 3.7)
project(showpic VERSION 1.0)

find_package(SDL2 REQUIRED)
include_directories(showpic ${SDL2_INCLUDE_DIRS})
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(showpic ${SOURCES})
target_link_libraries(showpic ${SDL2_LIBRARIES})
