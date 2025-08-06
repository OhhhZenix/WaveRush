cmake_minimum_required(VERSION 3.16)
project(WaveRush)

set(OUT_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)
set(BUILD_SHARED_LIBS OFF)

include(cmake/GLM.cmake)
include(cmake/SDL.cmake)

# Set lib options
# set(SDL2TTF_VENDORED ON CACHE INTERNAL "")

add_executable(
    ${PROJECT_NAME}
    src/Main.cpp
    src/Core/Global.cpp
    src/Entity/Player.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    # glm
    glm::glm
    # sdl
    $<TARGET_NAME_IF_EXISTS:SDL3::SDL3main>
    $<IF:$<TARGET_EXISTS:SDL3::SDL3>,SDL3::SDL3,SDL3::SDL3-static>
    # sdl ttf
    # $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
    # sdl image
    # $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
