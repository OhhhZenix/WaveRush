#pragma once

#include <cstddef>

struct wr_vertex_buffer {
  unsigned int id;
};

void wr_vertex_buffer_init(wr_vertex_buffer* vertex_buffer, const void* data,
                           size_t size, unsigned int usage);
void wr_vertex_buffer_cleanup(wr_vertex_buffer* vertex_buffer);
void wr_vertex_buffer_bind(wr_vertex_buffer* vertex_buffer);
void wr_vertex_buffer_unbind();