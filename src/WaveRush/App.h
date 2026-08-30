#pragma once

#include "WaveRush/Sokol.h"
#include <glm/glm.hpp>

namespace wr
{

class App
{
  public:
    void init();
    void frame();
    void event(const sapp_event *e);
    void cleanup();

  private:
    sg_pass_action pass_action_ = {};
    sg_pipeline quad_pip_ = {};
    sg_bindings quad_bind_ = {};
};

}; // namespace wr