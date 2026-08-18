#include "IndexBuffer.h"

#include <glad/glad.h>

namespace wr {

IndexBuffer::IndexBuffer(const void* data, std::uint32_t count,
                         std::uint32_t usage) {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, usage);
}

IndexBuffer::~IndexBuffer() { glDeleteBuffers(1, &id_); }

void IndexBuffer::bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_); }

void IndexBuffer::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

}  // namespace wr