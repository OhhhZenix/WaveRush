# Use vcpkg for library management and as main toolchain
# This cmake module require cmake version 3.16 or higher

if (EXISTS ${CMAKE_BINARY_DIR}/vcpkg)
    execute_process(COMMAND git pull WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/vcpkg)
else()
    execute_process(COMMAND git clone --branch master --recursive https://github.com/microsoft/vcpkg.git WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
message(STATUS "CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")