#pragma once

#include <SDL3/SDL.h>

#include <memory>

#include "WaveRush/Engine/IndexBuffer.h"
#include "WaveRush/Engine/Shader.h"
#include "WaveRush/Engine/VertexArray.h"
#include "WaveRush/Engine/VertexBuffer.h"

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

 private:
  SDL_Window* window_;
  SDL_GLContext gl_;
  std::unique_ptr<wr::Shader> shader_;
  std::unique_ptr<wr::VertexArray> vao_;
  std::unique_ptr<wr::VertexBuffer> vbo_;
  std::unique_ptr<wr::IndexBuffer> ibo_;
};

};  // namespace wr