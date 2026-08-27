cmake_minimum_required(VERSION 4.3)
project(WaveRush LANGUAGES CXX OBJCXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/sokol.cmake)
include(cmake/sokol-tools-bin.cmake)
include(cmake/glm.cmake)

add_executable(
        ${PROJECT_NAME}
        src/Main.cc
        src/WaveRush/App.cc
)

if(APPLE)
        set_source_files_properties(src/Main.cc PROPERTIES LANGUAGE OBJCXX)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} PRIVATE sokol)

target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)

add_custom_command(
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT ${CMAKE_SOURCE_DIR}/src/WaveRush/Shader.h
        COMMAND
        "${SOKOL_SHDC_PATH}"
        --input assets/shader.glsl
        --output src/WaveRush/Shader.h
        --slang spirv_vk:glsl430:metal_macos:wgsl
        DEPENDS ${CMAKE_SOURCE_DIR}/assets/shader.glsl
        COMMENT "Generating shader header from shader.glsl"
)

add_custom_target(generate_shaders DEPENDS ${CMAKE_SOURCE_DIR}/src/WaveRush/Shader.h)

add_dependencies(${PROJECT_NAME} generate_shaders)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
