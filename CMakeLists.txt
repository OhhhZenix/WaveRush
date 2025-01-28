cmake_minimum_required(VERSION 3.31)

# Standard
# set(CMAKE_C_STANDARD 23)
# set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create the project
project(WaveRush)

# Add FetchContent
include(FetchContent)

# Setup nebula
FetchContent_Declare(
    nebula
    GIT_REPOSITORY https://github.com/OhhhZenix/nebula
    GIT_TAG main
)
set(BUILD_SHARED_LIBS ON CACHE INTERNAL "")

# Bring content to scope
FetchContent_MakeAvailable(nebula)

# Add the executable
add_executable(
    ${PROJECT_NAME}
    src/main.c
    src/core/allocator.c
)

# Add the include folder
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Linking nebula
target_link_libraries(${PROJECT_NAME} PRIVATE nebula)

# Copy nebula
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:nebula>
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# Copy assets folder
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
