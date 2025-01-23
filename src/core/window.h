#pragma once

#include <stdbool.h>
#include <stdint.h>

void WindowInit(const char* title, uint32_t width, uint32_t height);
void WindowCleanup();
void WindowPollEvents();
bool WindowShouldClose();
