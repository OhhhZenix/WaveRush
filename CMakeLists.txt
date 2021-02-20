cmake_minimum_required(VERSION 3.17)
project(WaveRush)

add_executable(WaveRush src/Main.cpp src/Utils.h)

set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_USE_STATIC_STD_LIBS ON)
add_subdirectory(deps/SFML)
target_link_libraries(WaveRush sfml-graphics)