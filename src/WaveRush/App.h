#pragma once

#include <SDL3/SDL.h>
#include <SDL3_shadercross/SDL_shadercross.h>

#include <glm/glm.hpp>
#include <string_view>

namespace wr {

class App {
 public:
  App() = default;
  ~App();
  App(const App&) = delete;
  App& operator=(const App&) = delete;
  App(App&&) = delete;
  App& operator=(App&&) = delete;
  SDL_AppResult init();
  SDL_AppResult iterate();
  SDL_AppResult event(SDL_Event* event);
  void draw_quad(glm::vec2 position, glm::vec2 size, glm::vec4 color);
  void draw_line(glm::vec2 position_a, glm::vec2 position_b, float thickness,
                 glm::vec4 color);

 private:
  SDL_GPUShader* load_shader(std::string_view path,
                             std::string_view entry_point,
                             SDL_ShaderCross_ShaderStage stage);

  SDL_Window* window_;
  SDL_GPUDevice* gpu_;
};

};  // namespace wr