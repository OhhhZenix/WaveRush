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

SDL_GPUShader* App::load_shader(std::string_view path,
                                std::string_view entry_point,
                                SDL_ShaderCross_ShaderStage stage) {
  std::size_t source_size = 0;
  char* source = (char*)SDL_LoadFile(path.data(), &source_size);

  if (source == nullptr) {
    SDL_Log("Failed to load shader '%s': %s", path.data(), SDL_GetError());
    return nullptr;
  }

  SDL_ShaderCross_HLSL_Info hlsl_info;
  hlsl_info.source = source;
  hlsl_info.entrypoint = entry_point.data();
  hlsl_info.shader_stage = stage;

  std::size_t spirv_size = 0;
  void* spirv = SDL_ShaderCross_CompileSPIRVFromHLSL(&hlsl_info, &spirv_size);
  SDL_free(source);

  if (spirv == nullptr) {
    SDL_Log("Failed to compile shader '%s': %s", path.data(), SDL_GetError());
    return nullptr;
  }

  SDL_ShaderCross_SPIRV_Info spirv_info;
  spirv_info.bytecode = (std::uint8_t*)spirv;
  spirv_info.bytecode_size = spirv_size;
  spirv_info.entrypoint = entry_point.data();
  spirv_info.shader_stage = stage;

  SDL_ShaderCross_GraphicsShaderMetadata* metadata =
      SDL_ShaderCross_ReflectGraphicsSPIRV((std::uint8_t*)spirv, spirv_size, 0);

  if (metadata == nullptr) {
    SDL_Log("Failed to reflect shader '%s': %s", path.data(), SDL_GetError());
    SDL_free(spirv);
    return nullptr;
  }

  SDL_GPUShader* shader = SDL_ShaderCross_CompileGraphicsShaderFromSPIRV(
      gpu_, &spirv_info, &metadata->resource_info, 0);

  SDL_free(metadata);
  SDL_free(spirv);

  return shader;
}

}  // namespace wr