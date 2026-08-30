#include "WaveRush/App.h"
#include "WaveRush/Contants.h"

void init(void *user_data)
{
    wr::App *app = static_cast<wr::App *>(user_data);
    app->init();
}

void frame(void *user_data)
{
    wr::App *app = static_cast<wr::App *>(user_data);
    app->frame();
}

void event(const sapp_event *e, void *user_data)
{
    wr::App *app = static_cast<wr::App *>(user_data);
    app->event(e);
}

void cleanup(void *user_data)
{
    wr::App *app = static_cast<wr::App *>(user_data);
    app->cleanup();
}

sapp_desc sokol_main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    static wr::App user_data;
    return (sapp_desc){
        .user_data = &user_data,
        .init_userdata_cb = init,
        .frame_userdata_cb = frame,
        .cleanup_userdata_cb = cleanup,
        .event_userdata_cb = event,
        .width = wr::GAME_WIDTH,
        .height = wr::GAME_HEIGHT,
        .window_title = wr::GAME_TITLE,
    };
}