#pragma once

#include <cstdint>

#include "WaveRush/Core/IndexBuffer.h"
#include "WaveRush/Core/VertexBuffer.h"

struct wr_vertex_array {
  uint32_t id;
};

void wr_vertex_array_init(wr_vertex_array* vertex_array);
void wr_vertex_array_cleanup(wr_vertex_array* vertex_array);
void wr_vertex_array_bind(wr_vertex_array* vertex_array);
void wr_vertex_array_unbind();
void wr_vertex_array_link_attribute(wr_vertex_array* vertex_array,
                                    wr_vertex_buffer* vertex_buffer,
                                    uint32_t layout_index, int32_t components,
                                    int32_t type, int32_t stride,
                                    const void* offset);
void wr_vertex_array_link_index_buffer(wr_vertex_array* vertex_array,
                                       wr_index_buffer* index_buffer);