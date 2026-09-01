#pragma once

#include "WaveRush/Sokol.h"

#include <cstdint>
#include <glm/glm.hpp>

namespace wr
{

struct QuadVertex
{
    glm::vec3 position;
    glm::vec4 color;
};

class App
{
  public:
    void init();
    void frame();
    void event(const sapp_event *e);
    void cleanup();
    void flush_quads();
    void draw_quad(const glm::vec2 &pos, const glm::vec2 &size, const glm::vec4 &color);

  private:
    sg_pass_action pass_action_ = {};
    sg_pipeline quad_pip_ = {};
    sg_bindings quad_bind_ = {};
    std::vector<QuadVertex> quad_vertices_ = {};
    std::vector<std::uint32_t> quad_indices_ = {};

    glm::mat4 camera_matrix_ = glm::mat4(1.0f);
};

}; // namespace wr