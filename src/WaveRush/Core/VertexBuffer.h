#pragma once

#include <cstddef>
#include <cstdint>

struct wr_vertex_buffer {
  uint32_t id;
};

void wr_vertex_buffer_init(wr_vertex_buffer* vertex_buffer, const void* data,
                           size_t size, uint32_t usage);
void wr_vertex_buffer_cleanup(wr_vertex_buffer* vertex_buffer);
void wr_vertex_buffer_bind(wr_vertex_buffer* vertex_buffer);
void wr_vertex_buffer_unbind();