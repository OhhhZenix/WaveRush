cmake_minimum_required(VERSION 3.16)

# Standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create the project
project(WaveRush)

# Add FetchContent
include(FetchContent)

# Setup SDL
FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-3.2.0
)
set(BUILD_SHARED_LIBS ON CACHE INTERNAL "")

# Bring content to scope
FetchContent_MakeAvailable(sdl)

# Add the executable
add_executable(
    ${PROJECT_NAME}
    src/main.c
    src/core/allocator.c
    src/core/engine.c
    src/core/window.c
    src/core/renderer.c
    src/core/input.c
)

# Add the include folder
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Linking SDL
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

# Copy SDL
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory $<TARGET_FILE_DIR:SDL3::SDL3>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# Copy assets folder
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
