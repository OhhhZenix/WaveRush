#pragma once

#include <cstddef>

struct Arena {
    size_t capacity;
    size_t used;
    void* buffer;
};

void wr_arena_init(Arena* arena, size_t capacity);

void wr_arena_deinit(Arena* arena);

void* wr_arena_push(Arena* arena, size_t size);

void wr_arena_reset(Arena* arena);