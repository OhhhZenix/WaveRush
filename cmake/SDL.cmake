include(FetchContent)

FetchContent_Declare(
    sdl
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.32.4
)

FetchContent_MakeAvailable(sdl)
