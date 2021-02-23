## Use vcpkg for library management and as main toolchain
## Try to find local installation first and download as backup
if (DEFINED ENV{VCPKG_ROOT})
    set(vcpkg_SOURCE_DIR $ENV{VCPKG_ROOT})
else (DEFINED ENV{VCPKG_ROOT})
    include(FetchContent)
    message(STATUS "Local vcpkg instance not found, cloning repo https://github.com/microsoft/vcpkg")
    FetchContent_Declare(vcpkg GIT_REPOSITORY "https://github.com/microsoft/vcpkg.git" GIT_TAG "master")
    FetchContent_MakeAvailable(vcpkg)
endif (DEFINED ENV{VCPKG_ROOT})

set(CMAKE_TOOLCHAIN_FILE "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake")
message(STATUS "Using vcpkg toolchain file: ${CMAKE_TOOLCHAIN_FILE}")