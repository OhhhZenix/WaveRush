cmake_minimum_required(VERSION 4.3)
project(WaveRush)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(cmake/SDL2.cmake)
include(cmake/SDL2_ttf.cmake)
include(cmake/glm.cmake)

# Target
set(TARGET_NAME WaveRush)
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_executable(${TARGET_NAME} ${SRCS})
target_include_directories(${TARGET_NAME} PUBLIC src)

# Linking libraries
target_link_libraries(${TARGET_NAME} PRIVATE SDL2 SDL2_ttf glm)

# Post build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
