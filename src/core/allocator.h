#pragma once

#include <stdint.h>

void ArenaInit(uint32_t size);
void ArenaCleanup();
void* ArenaAlloc(uint32_t size);
