#include "Arena.h"

#include <cstdlib>

void wr_arena_init(wr_arena* arena, size_t size) {
  arena->memory = (char*)malloc(size);
  arena->size = size;
  arena->offset = 0;
}

void wr_arena_cleanup(wr_arena* arena) {
  free(arena->memory);
  arena->memory = nullptr;
  arena->size = 0;
  arena->offset = 0;
}

void* wr_arena_alloc(wr_arena* arena, size_t size) {
  if (arena->offset + size > arena->size) {
    return nullptr;  // Not enough memory
  }
  void* ptr = arena->memory + arena->offset;
  arena->offset += size;
  return ptr;
}