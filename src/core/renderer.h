#pragma once

#include <stdint.h>

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

void RendererInit(void* window);
void RendererCleanup();
void RenderBegin(struct Color color);
void RenderEnd();
void DrawRectangle(int32_t x, int32_t y, uint32_t width, uint32_t height, struct Color color);
