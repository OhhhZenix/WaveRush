#pragma once

#if defined(__EMSCRIPTEN__)
#define SOKOL_WGPU
#elif defined(__APPLE__)
#define SOKOL_METAL
#elif defined(__linux__)
#define SOKOL_VULKAN
#elif defined(_WIN32)
#define SOKOL_D3D11
#else
#error "platform not supported"
#endif

#include <sokol_app.h>
#include <sokol_args.h>
#include <sokol_audio.h>
#include <sokol_fetch.h>
#include <sokol_gfx.h>
#include <sokol_glue.h>
#include <sokol_log.h>
#include <sokol_time.h>