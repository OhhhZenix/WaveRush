include(FetchContent)

FetchContent_Declare(
    SDL3_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf
    GIT_TAG        release-3.2.2
)

FetchContent_MakeAvailable(SDL3_ttf)
