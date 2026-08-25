include(FetchContent)

FetchContent_Declare(
    sokol_tools_bin
    GIT_REPOSITORY https://github.com/floooh/sokol-tools-bin
    GIT_TAG master
)

FetchContent_MakeAvailable(sokol_tools_bin)

if(WIN32)
    set(SOKOL_SHDC_PATH "${sokol_tools_bin_SOURCE_DIR}/bin/win32/sokol-shdc.exe")
elseif(APPLE)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
        set(SOKOL_SHDC_PATH "${sokol_tools_bin_SOURCE_DIR}/bin/osx_arm64/sokol-shdc")
    else()
        set(SOKOL_SHDC_PATH "${sokol_tools_bin_SOURCE_DIR}/bin/osx/sokol-shdc")
    endif()
elseif(UNIX)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
        set(SOKOL_SHDC_PATH "${sokol_tools_bin_SOURCE_DIR}/bin/linux_arm64/sokol-shdc")
    else()
        set(SOKOL_SHDC_PATH "${sokol_tools_bin_SOURCE_DIR}/bin/linux/sokol-shdc")
    endif()
else()
    message(FATAL_ERROR "Platform not supported for sokol shdc.")
endif()
