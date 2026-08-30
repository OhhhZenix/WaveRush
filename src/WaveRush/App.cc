#include "App.h"

namespace wr
{

void App::init()
{
    sg_setup((sg_desc){
        .logger = {.func = slog_func},
        .environment = sglue_environment(),
    });

    pass_action_.colors[0] = {
        .load_action = SG_LOADACTION_CLEAR,
        .clear_value = {1.0f, 0.0f, 0.0f, 1.0f},
    };
}

void App::frame()
{
    sg_begin_pass((sg_pass){
        .action = pass_action_,
        .swapchain = sglue_swapchain(),
    });
    sg_end_pass();
    sg_commit();
}

void App::event(const sapp_event *e)
{
}

void App::cleanup()
{
    sg_shutdown();
}

} // namespace wr