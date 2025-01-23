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
FetchContent_MakeAvailable(raylib)

# Add the executable
add_executable(
    ${PROJECT_NAME}
    src/main.c
    src/core/allocator.c
    src/core/window.c
)

# Add the include folder
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Linking raylib
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Post build
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory $<TARGET_FILE_DIR:raylib>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
