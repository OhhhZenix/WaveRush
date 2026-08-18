#pragma once

#include <cstdint>

namespace wr {

class IndexBuffer {
 public:
  IndexBuffer(const void* data, std::uint32_t count, std::uint32_t usage);
  ~IndexBuffer();
  IndexBuffer(const IndexBuffer&) = delete;
  IndexBuffer& operator=(const IndexBuffer&) = delete;
  IndexBuffer(IndexBuffer&&) = delete;
  IndexBuffer& operator=(IndexBuffer&&) = delete;
  void bind() const;
  void unbind() const;
  std::uint32_t get_count() const { return count_; }

 private:
  std::uint32_t id_;
  std::uint32_t count_;
};

}  // namespace wr