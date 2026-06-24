cmake_minimum_required(VERSION 4.3)
project(WaveRush)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/SDL3.cmake)
include(cmake/SDL3_ttf.cmake)
include(cmake/glm.cmake)

add_executable(
        ${PROJECT_NAME}
        src/Main.cpp
        src/WaveRush/Core/Game.cpp
        src/WaveRush/Core/Arena.cpp
        src/WaveRush/Core/Queue.cpp
        src/WaveRush/Entity/World.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf glm)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
