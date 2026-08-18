#include "App.h"

#include <SDL3/SDL_init.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <memory>

namespace wr {

App::~App() {
  SDL_GL_DestroyContext(gl_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

SDL_AppResult App::init() {
  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  window_ = SDL_CreateWindow("WaveRush", 640, 360, SDL_WINDOW_OPENGL);

  if (window_ == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  gl_ = SDL_GL_CreateContext(window_);

  if (gl_ == nullptr) {
    SDL_Log("Failed to create OpenGL context: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
    SDL_Log("Failed to initialize Glad: No GL driver has been loaded");
    return SDL_APP_FAILURE;
  }

  SDL_Log("OpenGL version: %s", glGetString(GL_VERSION));

  shader_ = std::make_unique<wr::Shader>(
      std::filesystem::path("assets/shaders/default.vert"),
      std::filesystem::path("assets/shaders/default.frag"));
  vbo_ = std::make_unique<wr::VertexBuffer>(nullptr, 0, GL_STATIC_DRAW);
  ibo_ = std::make_unique<wr::IndexBuffer>(nullptr, 0, GL_STATIC_DRAW);
  vao_ = std::make_unique<wr::VertexArray>();

  vao_->link_attribute(*vbo_, 0, 0, 0, 0, nullptr);
  vao_->link_index_buffer(*ibo_);

  return SDL_APP_CONTINUE;
}

SDL_AppResult App::iterate() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  shader_->set_vec4("ourColor", glm::vec4(1.f, 0.5f, 0.f, 1.f));
  SDL_GL_SwapWindow(window_);
  return SDL_APP_CONTINUE;
}

SDL_AppResult App::event(SDL_Event* event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }

  return SDL_APP_CONTINUE;
}

}  // namespace wr