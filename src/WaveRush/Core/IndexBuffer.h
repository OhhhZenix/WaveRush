#pragma once

#include <cstdint>

struct wr_index_buffer {
  uint32_t id;
  uint32_t count;
};

void wr_index_buffer_init(wr_index_buffer* index_buffer,
                          const uint32_t* indices, uint32_t count,
                          uint32_t usage);
void wr_index_buffer_cleanup(wr_index_buffer* index_buffer);
void wr_index_buffer_bind(wr_index_buffer* index_buffer);
void wr_index_buffer_unbind();
