#include "WindowSettings.hpp"

WindowSettings window_settings_create()
{
    WindowSettings settings;
    settings.title = "WaveRush";
    settings.width = 1280;
    settings.height = 720;
    return settings;
}