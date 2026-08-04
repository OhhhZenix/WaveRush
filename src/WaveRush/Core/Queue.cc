#include "Queue.h"

void wr_queue_init(wr_queue *queue, size_t capacity, size_t element_size,
                   wr_arena *arena) {
  queue->buffer = (char *)wr_arena_alloc(arena, element_size * capacity);
  queue->element_size = element_size;
  queue->capacity = capacity;
  queue->size = 0;
  queue->head = 0;
  queue->tail = 0;
}

bool wr_queue_push(wr_queue *queue, const void *element) {
  if (queue->size == queue->capacity) return false;

  memcpy(queue->buffer + queue->tail * queue->element_size, element,
         queue->element_size);

  queue->tail = (queue->tail + 1) % queue->capacity;
  queue->size++;

  return true;
}

bool wr_queue_pop(wr_queue *queue, void *out) {
  if (queue->size == 0) return false;

  memcpy(out, queue->buffer + queue->head * queue->element_size,
         queue->element_size);

  queue->head = (queue->head + 1) % queue->capacity;
  queue->size--;

  return true;
}
