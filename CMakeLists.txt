cmake_minimum_required(VERSION 3.30)

# Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Create the project
project(WaveRush)

# Add FetchContent
include(FetchContent)

# Setup glm
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm
    GIT_TAG 1.0.1
)

# Setup sdl
FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-3.2.4
)

# Setup sdl_image
FetchContent_Declare(
    sdl_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
    GIT_TAG release-3.2.0
)

# Set lib options
set(SDL_TESTS OFF CACHE INTERNAL "")
set(SDL_EXAMPLES OFF CACHE INTERNAL "")
set(SDLIMAGE_TESTS OFF CACHE INTERNAL "")
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")

# Bring content to scope
FetchContent_MakeAvailable(glm sdl sdl_image)

# Add the executable
add_executable(
    ${PROJECT_NAME}
    src/Main.cpp
    src/Core/Game.cpp
    src/Entity/BasicEnemy.cpp
    src/Entity/Player.cpp
)

# Add the include folder
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Linking nebula
target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    glm::glm 
    SDL3::SDL3 
    SDL3_image::SDL3_image
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
