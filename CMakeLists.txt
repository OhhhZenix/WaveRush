cmake_minimum_required(VERSION 3.16)

# Sets up vcpkg
include(cmake/VcpkgToolchain.cmake)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the project
project(WaveRush)

# Finding SDL
find_package(SDL2 CONFIG REQUIRED)

# Finding SDL-TTF
find_package(sdl2-ttf CONFIG REQUIRED)

# Target
set(TARGET_NAME WaveRush)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_executable(${TARGET_NAME} ${SRCS})
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Core/PCH.hpp)

# Linking SDL
target_link_libraries(${TARGET_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Linking SDL-TTF
target_link_libraries(${TARGET_NAME} PRIVATE SDL2::SDL2_ttf)

# Post build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
