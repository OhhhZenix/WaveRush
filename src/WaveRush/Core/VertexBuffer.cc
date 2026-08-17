#include "VertexBuffer.h"

#include <glad/glad.h>

void wr_vertex_buffer_init(wr_vertex_buffer* vertex_buffer, const void* data,
                           size_t size, unsigned int usage) {
  glGenBuffers(1, &vertex_buffer->id);
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->id);
  glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void wr_vertex_buffer_cleanup(wr_vertex_buffer* vertex_buffer) {
  glDeleteBuffers(1, &vertex_buffer->id);
}

void wr_vertex_buffer_bind(wr_vertex_buffer* vertex_buffer) {
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->id);
}

void wr_vertex_buffer_unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }