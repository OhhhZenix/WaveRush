#pragma once

#include <glm/glm.hpp>
#include <sokol_gfx.h>

namespace wr
{

struct RenderData
{
    sg_pass_action pass_action = {};
};

class App
{
  public:
    App();
    ~App();
    App(const App &) = delete;
    App &operator=(const App &) = delete;
    App(App &&) = delete;
    App &operator=(App &&) = delete;
    void run();
    RenderData &get_render_data();

  private:
    bool running_ = false;
    RenderData render_data_;
};

}; // namespace wr