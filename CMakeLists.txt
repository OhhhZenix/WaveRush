cmake_minimum_required(VERSION 3.16)

# Sets up vcpkg
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE PATH "Path to vcpkg toolchain")
message(STATUS "CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}") 

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the project
project(WaveRush)

# Finding SDL
find_package(SDL2 REQUIRED)

# Finding glm
find_package(glm REQUIRED)

# Finding EnTT
find_package(EnTT REQUIRED)

# Target
file(GLOB_RECURSE SRCS "src/*.cpp" "src/*.hpp")
add_executable(WaveRush ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Linking SDL
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

# Linking glm
target_link_libraries(${PROJECT_NAME} PRIVATE glm)

# Linking EnTT
target_link_libraries(${PROJECT_NAME} PRIVATE EnTT::EnTT)

# Post build
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
