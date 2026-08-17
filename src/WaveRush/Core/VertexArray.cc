#include "VertexArray.h"

#include <glad/glad.h>

#include "WaveRush/Core/VertexBuffer.h"

void wr_vertex_array_init(wr_vertex_array* vertex_array) {
  glGenVertexArrays(1, &vertex_array->id);
}

void wr_vertex_array_cleanup(wr_vertex_array* vertex_array) {
  glDeleteVertexArrays(1, &vertex_array->id);
}

void wr_vertex_array_bind(wr_vertex_array* vertex_array) {
  glBindVertexArray(vertex_array->id);
}

void wr_vertex_array_unbind() { glBindVertexArray(0); }

void wr_vertex_array_link_attribute(wr_vertex_array* vertex_array,
                                    wr_vertex_buffer* vertex_buffer,
                                    uint32_t layout_index, int32_t components,
                                    int32_t type, int32_t stride,
                                    const void* offset) {
  wr_vertex_array_bind(vertex_array);
  wr_vertex_buffer_bind(vertex_buffer);

  glVertexAttribPointer(layout_index, components, type, GL_FALSE, stride,
                        offset);
  glEnableVertexAttribArray(layout_index);

  wr_vertex_buffer_unbind();
  wr_vertex_array_unbind();
}