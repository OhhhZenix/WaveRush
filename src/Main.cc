#define SOKOL_IMPL

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
#include <sokol_gfx.h>
#include <sokol_glue.h>
#include <sokol_log.h>

sg_pass_action pass_action;

void init(void)
{
    sg_setup((sg_desc){
        .logger = {.func = slog_func},
        .environment = sglue_environment(),
    });

    pass_action.colors[0] = {
        .load_action = SG_LOADACTION_CLEAR,
        .clear_value = {1.0f, 0.0f, 0.0f, 1.0f},
    };
}

void frame(void)
{
    float g = pass_action.colors[0].clear_value.g + 0.01f;
    pass_action.colors[0].clear_value.g = (g > 1.0f) ? 0.0f : g;
    sg_begin_pass((sg_pass){.action = pass_action, .swapchain = sglue_swapchain()});
    sg_end_pass();
    sg_commit();
}

void event(const sapp_event *e)
{
}

void cleanup(void)
{
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char *argv[])
{
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
        .width = 640,
        .height = 360,
        .window_title = "Wave Rush",
    };
}