#include "VertexArray.h"

#include <glad/glad.h>

namespace wr {

VertexArray::VertexArray() { glGenVertexArrays(1, &id_); }

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &id_); }

void VertexArray::bind() const { glBindVertexArray(id_); }

void VertexArray::unbind() const { glBindVertexArray(0); }

void VertexArray::link_attribute(const VertexBuffer& vbo,
                                 std::uint32_t layout_index, int components,
                                 int type, int stride, const void* offset) {
  vbo.bind();
  glVertexAttribPointer(layout_index, components, type, GL_FALSE, stride,
                        offset);
  glEnableVertexAttribArray(layout_index);
}

void VertexArray::link_index_buffer(const IndexBuffer& ibo) { ibo.bind(); }

}  // namespace wr