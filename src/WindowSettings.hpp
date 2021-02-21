#pragma once

#include <iostream>

struct WindowSettings
{
    std::string title;
    uint32_t width;
    uint32_t height;
};

WindowSettings window_settings_create();