include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG        release-2.30.12
)

FetchContent_MakeAvailable(SDL2)
