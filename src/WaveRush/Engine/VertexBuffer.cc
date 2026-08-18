#include "VertexBuffer.h"

#include <glad/glad.h>

namespace wr {

VertexBuffer::VertexBuffer(const void* data, std::size_t size,
                           std::uint32_t usage) {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ARRAY_BUFFER, id_);
  glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &id_); }

void VertexBuffer::bind() const { glBindBuffer(GL_ARRAY_BUFFER, id_); }

void VertexBuffer::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

}  // namespace wr