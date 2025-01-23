cmake_minimum_required(VERSION 3.16)

# Standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create the project
project(WaveRush)

# Add FetchContent
include(FetchContent)

# Setup raylib
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib
  GIT_TAG 5.5
)

# Target
set(TARGET_NAME WaveRush)
file(GLOB_RECURSE SRCS "src/*.c")
add_executable(${TARGET_NAME} ${SRCS})
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Core/PCH.hpp)

# Linking raylib
target_link_libraries(${TARGET_NAME} PRIVATE raylib)

# Post build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/assets 
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
