#pragma once

#include <cstdint>

#include "WaveRush/Engine/IndexBuffer.h"
#include "WaveRush/Engine/VertexBuffer.h"

namespace wr {

class VertexArray {
 public:
  VertexArray();
  ~VertexArray();
  VertexArray(const VertexArray&) = delete;
  VertexArray& operator=(const VertexArray&) = delete;
  VertexArray(VertexArray&&) = delete;
  VertexArray& operator=(VertexArray&&) = delete;
  void bind() const;
  void unbind() const;
  void link_attribute(const VertexBuffer& vbo, std::uint32_t layout_index,
                      int components, int type, int stride, const void* offset);
  void link_index_buffer(const IndexBuffer& ibo);

 private:
  std::uint32_t id_;
};

}  // namespace wr