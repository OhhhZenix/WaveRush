#pragma once

#include <cstddef>

#include "WaveRush/Core/Arena.h"

template <typename T>
struct wr_queue {
  T* data;
  size_t length;
  size_t count;
  size_t head;
  size_t tail;
};

template <typename T>
void wr_queue_init(wr_queue<T>* queue, size_t length, wr_arena* arena) {
  queue->data = (T*)wr_arena_alloc(arena, sizeof(T) * length);
  queue->length = length;
  queue->count = 0;
  queue->head = 0;
  queue->tail = 0;
}

template <typename T>
bool wr_queue_push(wr_queue<T>* queue, T element) {
  if (queue->count == queue->length) {
    return false;  // full
  }

  queue->data[queue->tail] = element;
  queue->tail = (queue->tail + 1) % queue->length;
  ++queue->count;

  return true;
}

template <typename T>
bool wr_queue_pop(wr_queue<T>* queue, T* out) {
  if (queue->count == 0) {
    return false;  // empty
  }

  *out = queue->data[queue->head];
  queue->head = (queue->head + 1) % queue->length;
  --queue->count;

  return true;
}
