#pragma once

#include <glm/glm.hpp>

#include "WaveRush/Core/IndexBuffer.h"
#include "WaveRush/Core/Shader.h"
#include "WaveRush/Core/VertexArray.h"
#include "WaveRush/Core/VertexBuffer.h"

struct wr_renderer {
  wr_shader shader;
  wr_vertex_array vertex_array;
  wr_vertex_buffer vertex_buffer;
  wr_index_buffer index_buffer;
  bool initialized;
};

void wr_renderer_init(wr_renderer* renderer);
void wr_renderer_cleanup(wr_renderer* renderer);
void wr_renderer_draw_rect(wr_renderer* renderer, glm::vec2 position,
                           glm::vec2 size, glm::vec4 color);