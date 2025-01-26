#pragma once

#include <stdint.h>

void arena_init(uint32_t size);
void arena_cleanup();
void* arena_alloc(uint32_t size);
