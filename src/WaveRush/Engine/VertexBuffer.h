#pragma once

#include <cstddef>
#include <cstdint>

namespace wr {

class VertexBuffer {
 public:
  VertexBuffer(const void* data, std::size_t size, std::uint32_t usage);
  ~VertexBuffer();
  VertexBuffer(const VertexBuffer&) = delete;
  VertexBuffer& operator=(const VertexBuffer&) = delete;
  VertexBuffer(VertexBuffer&&) = delete;
  VertexBuffer& operator=(VertexBuffer&&) = delete;
  void bind() const;
  void unbind() const;

 private:
  std::uint32_t id_;
};

}  // namespace wr