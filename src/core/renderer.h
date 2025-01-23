#pragma once

#include <stdint.h>

void RendererInit(void* window);
void RendererCleanup();
void RenderBegin();
void RenderEnd();
void DrawRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height);
