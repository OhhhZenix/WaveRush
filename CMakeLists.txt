cmake_minimum_required(VERSION 3.17)
project(WaveRush)

file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(WaveRush ${SRCS})

set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_USE_STATIC_STD_LIBS ON)
add_subdirectory(deps/SFML)
target_link_libraries(WaveRush sfml-graphics)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)