cmake_minimum_required(VERSION 3.16)
project(WaveRush)

set(OUT_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)
set(BUILD_SHARED_LIBS OFF)

include(cmake/raylib.cmake)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/wr/core/array_list.cpp
    src/wr/entity/enemy/bouncer.cpp
    src/wr/entity/enemy/seeker.cpp
    src/wr/entity/player.cpp
    src/wr/scene/play_scene.cpp
    src/wr/utils.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    raylib
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
