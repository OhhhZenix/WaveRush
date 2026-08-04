#pragma once

#if defined(__APPLE__)
#define SOKOL_METAL
#elif defined(__EMSCRIPTEN__)
#define SOKOL_WGPU
#else
#define SOKOL_GLCORE
#endif

#include <sokol_app.h>
#include <sokol_args.h>
#include <sokol_audio.h>
#include <sokol_fetch.h>
#include <sokol_gfx.h>
#include <sokol_glue.h>
#include <sokol_log.h>
#include <sokol_time.h>