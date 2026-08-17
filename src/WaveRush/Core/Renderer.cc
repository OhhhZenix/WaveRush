#include "Renderer.h"

#include <glad/glad.h>

static const char* k_renderer_vertex_shader = R"(
#version 330 core
layout (location = 0) in vec2 aPos;

void main() {
  gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

static const char* k_renderer_fragment_shader = R"(
#version 330 core
out vec4 FragColor;
uniform vec4 u_color;

void main() {
  FragColor = u_color;
}
)";

void wr_renderer_init(wr_renderer* renderer) {
  if (renderer == nullptr || renderer->initialized) {
    return;
  }

  wr_shader_init(&renderer->shader, k_renderer_vertex_shader,
                 k_renderer_fragment_shader);

  wr_vertex_array_init(&renderer->vertex_array);

  float vertices[] = {
      0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
  };

  uint32_t indices[] = {0, 1, 2, 2, 3, 0};

  wr_vertex_buffer_init(&renderer->vertex_buffer, vertices, sizeof(vertices),
                        GL_STATIC_DRAW);
  wr_index_buffer_init(&renderer->index_buffer, indices, 6, GL_STATIC_DRAW);

  wr_vertex_array_link_attribute(&renderer->vertex_array,
                                 &renderer->vertex_buffer, 0, 2, GL_FLOAT,
                                 2 * sizeof(float), (void*)0);
  wr_vertex_array_link_index_buffer(&renderer->vertex_array,
                                    &renderer->index_buffer);

  renderer->initialized = true;
}

void wr_renderer_cleanup(wr_renderer* renderer) {
  if (renderer == nullptr || !renderer->initialized) {
    return;
  }

  wr_index_buffer_cleanup(&renderer->index_buffer);
  wr_vertex_buffer_cleanup(&renderer->vertex_buffer);
  wr_vertex_array_cleanup(&renderer->vertex_array);
  wr_shader_cleanup(&renderer->shader);

  renderer->initialized = false;
}

void wr_renderer_draw_rect(wr_renderer* renderer, glm::vec2 position,
                           glm::vec2 size, glm::vec4 color) {
  if (renderer == nullptr) {
    return;
  }

  if (!renderer->initialized) {
    wr_renderer_init(renderer);
  }

  float vertices[] = {
      position.x, position.y,          position.x + size.x,
      position.y, position.x + size.x, position.y + size.y,
      position.x, position.y + size.y,
  };

  wr_vertex_array_bind(&renderer->vertex_array);
  wr_vertex_buffer_bind(&renderer->vertex_buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
  wr_shader_bind(&renderer->shader);
  wr_shader_set_vec4(&renderer->shader, "u_color", color);
  glDrawElements(GL_TRIANGLES, renderer->index_buffer.count, GL_UNSIGNED_INT,
                 0);
  wr_vertex_array_unbind();
}
