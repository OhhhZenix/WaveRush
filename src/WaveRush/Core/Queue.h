#pragma once

#include <cstddef>
#include <cstring>

#include "WaveRush/Core/Arena.h"

struct wr_queue {
  char *buffer;
  size_t element_size;
  size_t capacity;  // maximum number of elements
  size_t size;      // current number of elements
  size_t head;      // next element to dequeue
  size_t tail;      // next position to enqueue
};

void wr_queue_init(wr_queue *queue, size_t capacity, size_t element_size,
                   wr_arena *arena);
bool wr_queue_push(wr_queue *queue, const void *element);
bool wr_queue_pop(wr_queue *queue, void *out);
