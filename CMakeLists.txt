cmake_minimum_required(VERSION 4.3)
project(WaveRush)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/raylib.cmake)
include(cmake/sokol.cmake)
include(cmake/sokol-tools-bin.cmake)
include(cmake/glm.cmake)

add_executable(
        ${PROJECT_NAME}
        src/Main.cc
        src/WaveRush/App.cc
)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
