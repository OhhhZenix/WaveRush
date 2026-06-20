#include "Game.h"

#include <cstdint>

namespace wr {

Game::Game() {
  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return;
  }

  window_ = SDL_CreateWindow("WaveRush", 640, 360, 0);

  if (window_ == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return;
  }

  SDL_GPUShaderFormat gpu_flags = {};
  gpu_flags |= SDL_GPU_SHADERFORMAT_SPIRV;
  gpu_flags |= SDL_GPU_SHADERFORMAT_DXIL;
  gpu_flags |= SDL_GPU_SHADERFORMAT_METALLIB;

  gpu_ = SDL_CreateGPUDevice(gpu_flags, false, nullptr);

  if (gpu_ == nullptr) {
    SDL_Log("Failed to create GPU device: %s", SDL_GetError());
    return;
  }

  if (SDL_ClaimWindowForGPUDevice(gpu_, window_) == false) {
    SDL_Log("Failed to claim window: %s", SDL_GetError());
    return;
  }

  running_ = true;
}

Game::~Game() {
  SDL_ReleaseWindowFromGPUDevice(gpu_, window_);
  SDL_DestroyGPUDevice(gpu_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

auto Game::run() -> void {
  wr_entity* e = wr_world_add_entity(&world_);
  e->type = wr_entity_type::Player;
  e->position = {100.0f, 100.0f};
  wr_world_remove_entity(&world_, e);

  while (running_) {
    SDL_Event event = {};
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running_ = false;
      }
    }

    SDL_GPUCommandBuffer* cmd = SDL_AcquireGPUCommandBuffer(gpu_);

    if (!cmd) {
      continue;
    }

    SDL_GPUTexture* swapchainTexture = nullptr;
    std::uint32_t width = 0;
    std::uint32_t height = 0;

    if (SDL_WaitAndAcquireGPUSwapchainTexture(cmd, window_, &swapchainTexture,
                                              &width, &height)) {
      if (swapchainTexture) {
        SDL_GPUColorTargetInfo colorTarget = {};
        colorTarget.texture = swapchainTexture;
        colorTarget.clear_color.r = 0.1f;
        colorTarget.clear_color.g = 0.2f;
        colorTarget.clear_color.b = 0.4f;
        colorTarget.clear_color.a = 1.0f;
        colorTarget.load_op = SDL_GPU_LOADOP_CLEAR;
        colorTarget.store_op = SDL_GPU_STOREOP_STORE;

        SDL_GPURenderPass* pass =
            SDL_BeginGPURenderPass(cmd, &colorTarget, 1, nullptr);
        // render
        SDL_EndGPURenderPass(pass);
      }
    }

    SDL_SubmitGPUCommandBuffer(cmd);
  }
}

}  // namespace wr