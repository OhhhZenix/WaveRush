#include "Game.h"

#include <cstdint>

#include "WaveRush/Entity/World.h"

void wr_game_init(wr_game* game) {
  if (SDL_Init(SDL_INIT_VIDEO) == false) {
    SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    return;
  }

  game->window = SDL_CreateWindow("WaveRush", 640, 360, 0);

  if (game->window == nullptr) {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return;
  }

  SDL_GPUShaderFormat gpu_flags = {};
  gpu_flags |= SDL_GPU_SHADERFORMAT_SPIRV;
  gpu_flags |= SDL_GPU_SHADERFORMAT_DXIL;
  gpu_flags |= SDL_GPU_SHADERFORMAT_METALLIB;

  game->gpu = SDL_CreateGPUDevice(gpu_flags, false, nullptr);

  if (game->gpu == nullptr) {
    SDL_Log("Failed to create GPU device: %s", SDL_GetError());
    return;
  }

  if (SDL_ClaimWindowForGPUDevice(game->gpu, game->window) == false) {
    SDL_Log("Failed to claim window: %s", SDL_GetError());
    return;
  }

  game->running = true;
}

void wr_game_cleanup(wr_game* game) {
  SDL_ReleaseWindowFromGPUDevice(game->gpu, game->window);
  SDL_DestroyGPUDevice(game->gpu);
  SDL_DestroyWindow(game->window);
  SDL_Quit();
}

void wr_game_run(wr_game* game) {
  while (game->running) {
    SDL_Event event = {};
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        game->running = false;
      }
    }

    SDL_GPUCommandBuffer* cmd = SDL_AcquireGPUCommandBuffer(game->gpu);

    if (!cmd) {
      continue;
    }

    SDL_GPUTexture* swapchainTexture = nullptr;
    uint32_t width = 0;
    uint32_t height = 0;

    if (SDL_WaitAndAcquireGPUSwapchainTexture(
            cmd, game->window, &swapchainTexture, &width, &height)) {
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
