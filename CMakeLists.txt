cmake_minimum_required(VERSION 3.17)
project(WaveRush)

# Target
file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(WaveRush ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC src)

# SFML
set(SDL_SHARED_ENABLED_BY_DEFAULT OFF)
set(SDL_STATIC_ENABLED_BY_DEFAULT ON)
add_subdirectory(deps/SDL)
target_include_directories(${PROJECT_NAME} PUBLIC deps/SDL/include)
target_link_libraries(${PROJECT_NAME} SDL2-static)

# Post build
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD 
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)