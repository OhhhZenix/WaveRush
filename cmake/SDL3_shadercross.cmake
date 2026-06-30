include(FetchContent)

FetchContent_Declare(
  SDL3_shadercross
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_shadercross
    GIT_TAG        main
)

set(SDLSHADERCROSS_DXC OFF CACHE BOOL "")
set(SDLSHADERCROSS_VENDORED ON CACHE BOOL "")

FetchContent_MakeAvailable(SDL3_shadercross)
