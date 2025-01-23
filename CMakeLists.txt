cmake_minimum_required(VERSION 3.16)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create the project
project(WaveRush)

# Add FetchContent
include(FetchContent)

# Setup SDL2
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL/
  GIT_TAG        release-2.30.11
)
FetchContent_MakeAvailable(SDL2)

# Setup SDL2_ttf
FetchContent_Declare(
  SDL2_ttf
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf/
  GIT_TAG        release-2.24.0
)
FetchContent_MakeAvailable(SDL2_ttf)

# Setup raylib
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib
  GIT_TAG 5.5
)

# Target
set(TARGET_NAME WaveRush)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_executable(${TARGET_NAME} ${SRCS})
target_include_directories(${TARGET_NAME} PUBLIC src)

# Creates precompiled header
target_precompile_headers(${TARGET_NAME} PRIVATE src/Core/PCH.hpp)

# Linking raylib
target_link_libraries(${TARGET_NAME} PRIVATE raylib)

# Linking SDL
target_link_libraries(${TARGET_NAME} PRIVATE SDL2 SDL2main)

# Linking SDL2_ttf
target_link_libraries(${TARGET_NAME} PRIVATE SDL2_ttf)

# Post build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/assets 
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
