#pragma once

#include <SDL3/SDL.h>

#include <glm/glm.hpp>

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
  SDL_Window* window_;
  SDL_GPUDevice* gpu_;

  SDL_GPUTransferBuffer* transfer_buffer_;
  SDL_GPUBuffer* vertex_buffer_;
  SDL_GPUGraphicsPipeline* graphics_pipeline_;

  SDL_GPUBuffer* quad_vertex_buffer_;
  SDL_GPUGraphicsPipeline* quad_graphics_pipeline_;

  SDL_GPUBuffer* circle_vertex_buffer_;
  SDL_GPUGraphicsPipeline* circle_graphics_pipeline_;

  SDL_GPUBuffer* line_vertex_buffer_;
  SDL_GPUGraphicsPipeline* line_graphics_pipeline_;
};

};  // namespace wr