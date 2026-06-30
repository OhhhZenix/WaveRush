include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG        release-3.4.10
)

set(SDL_EXAMPLES OFF CACHE BOOL "")

FetchContent_MakeAvailable(SDL3)
