cmake_minimum_required(VERSION 3.17)

include(CMAKE/SetupVcpkg.cmake)

set(ListP "sdl2")
SetupVcpkg(${ListP})

project(WaveRush)

find_package(SDL2 CONFIG REQUIRED)

# Target
file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(WaveRush ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC src)

# SDL
#add_subdirectory(deps/SDL)
#target_include_directories(${PROJECT_NAME} PUBLIC deps/SDL/include)
#target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static)


target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Post build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)