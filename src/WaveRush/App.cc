#include "App.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3_shadercross/SDL_shadercross.h>

#include <cstdint>
#include <glm/glm.hpp>

namespace wr {

App::~App() {
  SDL_ReleaseWindowFromGPUDevice(gpu_, window_);
  SDL_DestroyGPUDevice(gpu_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

SDL_AppResult App::init() {
  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  window_ = SDL_CreateWindow("WaveRush", 640, 360, 0);

  if (window_ == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  gpu_ = SDL_CreateGPUDevice(SDL_ShaderCross_GetSPIRVShaderFormats(), false,
                             nullptr);

  if (gpu_ == nullptr) {
    SDL_Log("Failed to create GPU device: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (SDL_ClaimWindowForGPUDevice(gpu_, window_) == false) {
    SDL_Log("Failed to claim window: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_Log("%s", SDL_GetGPUDeviceDriver(gpu_));

  return SDL_APP_CONTINUE;
}

SDL_AppResult App::iterate() {
  SDL_GPUCommandBuffer* command_buffer = SDL_AcquireGPUCommandBuffer(gpu_);

  SDL_GPUTexture* swapchain_texture;
  std::uint32_t width;
  std::uint32_t height;
  SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, window_,
                                        &swapchain_texture, &width, &height);

  if (swapchain_texture != nullptr) {
    SDL_GPUColorTargetInfo color_target_info = {
        .texture = swapchain_texture,
        .clear_color =
            {
                255 / 255.0f,
                219 / 255.0f,
                187 / 255.0f,
                255 / 255.0f,
            },
        .load_op = SDL_GPU_LOADOP_CLEAR,
        .store_op = SDL_GPU_STOREOP_STORE,
    };
    SDL_GPURenderPass* render_pass =
        SDL_BeginGPURenderPass(command_buffer, &color_target_info, 1, nullptr);
    // do stuff
    SDL_EndGPURenderPass(render_pass);
  }

  SDL_SubmitGPUCommandBuffer(command_buffer);
  return SDL_APP_CONTINUE;
}

SDL_AppResult App::event(SDL_Event* event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }

  return SDL_APP_CONTINUE;
}

void App::draw_quad(glm::vec2 position, glm::vec2 size, glm::vec4 color) {}

}  // namespace wr