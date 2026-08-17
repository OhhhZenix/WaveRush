#include "IndexBuffer.h"

#include <glad/glad.h>

void wr_index_buffer_init(wr_index_buffer* index_buffer,
                          const uint32_t* indices, uint32_t count,
                          uint32_t usage) {
  glGenBuffers(1, &index_buffer->id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), indices, usage);
}

void wr_index_buffer_cleanup(wr_index_buffer* index_buffer) {
  glDeleteBuffers(1, &index_buffer->id);
}

void wr_index_buffer_bind(wr_index_buffer* index_buffer) {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->id);
}

void wr_index_buffer_unbind() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }