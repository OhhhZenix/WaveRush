#pragma once

#include <cstddef>

struct wr_arena {
  char* memory;
  size_t size;
  size_t offset;
};

void wr_arena_init(wr_arena* arena, size_t size);
void wr_arena_cleanup(wr_arena* arena);
void* wr_arena_alloc(wr_arena* arena, size_t size);