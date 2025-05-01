cmake_minimum_required(VERSION 3.16)

# Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Create the project
project(WaveRush)

# Add FetchContent
include(FetchContent)

# Setup sdl
FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.32.4
)

# Setup sdl_ttf
FetchContent_Declare(
    sdl_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf
    GIT_TAG release-2.24.0
)

# Setup sdl_image
FetchContent_Declare(
    sdl_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
    GIT_TAG release-2.8.8
)

# Set lib options
set(SDL2TTF_VENDORED ON CACHE INTERNAL "")

# Bring content to scope
FetchContent_MakeAvailable(sdl sdl_ttf sdl_image)

# Add the executable
add_executable(
    ${PROJECT_NAME}
    src/Core/FontManager.cpp
    src/Core/Game.cpp
    src/Core/Timer.cpp
    src/Entity/BasicEnemy.cpp
    src/Entity/Entity.cpp
    src/Entity/EntityManager.cpp
    src/Entity/ParticleSystem.cpp
    src/Entity/Player.cpp
    src/Entity/SmartEnemy.cpp
    src/GUI/Text.cpp
    src/GUI/Widget.cpp
    src/GUI/WidgetManager.cpp
    src/Scene/MainMenuScene.cpp
    src/Scene/PlayScene.cpp
    src/Scene/Scene.cpp
    src/Scene/SceneManager.cpp
    src/Main.cpp
)

# Creates precompiled header
target_precompile_headers(${PROJECT_NAME} PRIVATE src/Core/PCH.hpp)

# Add the include folder
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Linking libraries
target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    # sdl
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    # sdl_ttf
    $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
    # sdl_image
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
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
