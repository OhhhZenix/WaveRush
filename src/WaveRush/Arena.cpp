#include "WaveRush/Arena.h"

#include <cassert>
#include <cstdlib>

void wr_arena_init(Arena* arena, size_t capacity) {
    arena->capacity = capacity;
    arena->used = 0;
    arena->buffer = malloc(capacity);
    assert(arena->buffer && "Failed to allocate the buffer");
}

void wr_arena_deinit(Arena* arena) {
    free(arena->buffer);
    arena->buffer = NULL;
    arena->used = 0;
    arena->capacity = 0;
}

void* wr_arena_push(Arena* arena, size_t size) {
    assert(arena->used + size <= arena->capacity && "Reached arena capacity");
    void* ptr = (char*)arena->buffer + arena->used;
    arena->used += size;
    return ptr;
}

void wr_arena_reset(Arena* arena) {
    arena->used = 0;
}