#include "WaveRush/App.h"
#include "WaveRush/Contants.h"
#include "WaveRush/Sokol.h"

#include <memory>

void init(void *user_data)
{
    wr::App *app = static_cast<wr::App *>(user_data);

    sg_setup((sg_desc){
        .logger = {.func = slog_func},
        .environment = sglue_environment(),
    });

    app->get_render_data().pass_action.colors[0] = {
        .load_action = SG_LOADACTION_CLEAR,
        .clear_value = {1.0f, 0.0f, 0.0f, 1.0f},
    };
}

void frame(void *user_data)
{
    wr::App *app = static_cast<wr::App *>(user_data);
    sg_pass_action &pass_action = app->get_render_data().pass_action;
    const float step = 0.01f;
    float g = pass_action.colors[0].clear_value.g + step;
    pass_action.colors[0].clear_value.g = (g > 1.0f) ? 0.0f : g;
    sg_begin_pass((sg_pass){.action = pass_action, .swapchain = sglue_swapchain()});
    sg_end_pass();
    sg_commit();
}

void event(const sapp_event *e, void *user_data)
{
}

void cleanup(void *user_data)
{
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    std::unique_ptr<wr::App> user_data = std::make_unique<wr::App>();
    return (sapp_desc){
        .user_data = &user_data,
        .init_userdata_cb = init,
        .frame_userdata_cb = frame,
        .cleanup_userdata_cb = cleanup,
        .event_userdata_cb = event,
        .width = wr::GAME_WIDTH,
        .height = wr::GAME_HEIGHT,
        .window_title = "Wave Rush",
    };
}