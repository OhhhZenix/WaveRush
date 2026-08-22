#include "App.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3_shadercross/SDL_shadercross.h>

#include <cstdint>
#include <glm/glm.hpp>
#include <string_view>

struct Vertex {
  float x, y, z;     // vec3 position
  float r, g, b, a;  // vec4 color
};

// a list of vertices
static Vertex vertices[]{
    {0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f},    // top vertex
    {-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f},  // bottom left vertex
    {0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f}    // bottom right vertex
};

SDL_GPUShader* load_shader(SDL_GPUDevice* gpu, std::string_view path,
                           std::string_view entry_point,
                           SDL_ShaderCross_ShaderStage stage) {
  size_t source_size = 0;
  char* source = (char*)SDL_LoadFile(path.data(), &source_size);
  if (source == nullptr) {
    SDL_Log("Failed to load shader '%s': %s", path.data(), SDL_GetError());
    return nullptr;
  }

  SDL_ShaderCross_HLSL_Info hlsl{};
  hlsl.source = source;
  hlsl.entrypoint = entry_point.data();
  hlsl.shader_stage = stage;

  size_t vertex_spirv_size = 0;
  void* spirv = SDL_ShaderCross_CompileSPIRVFromHLSL(&hlsl, &vertex_spirv_size);
  SDL_free(source);
  if (spirv == nullptr) {
    SDL_Log("Failed to compile shader '%s': %s", path.data(), SDL_GetError());
    return nullptr;
  }

  SDL_ShaderCross_SPIRV_Info info{};
  info.bytecode = (Uint8*)spirv;
  info.bytecode_size = vertex_spirv_size;
  info.entrypoint = entry_point.data();
  info.shader_stage = stage;

  SDL_ShaderCross_GraphicsShaderMetadata* metadata =
      SDL_ShaderCross_ReflectGraphicsSPIRV((Uint8*)spirv, vertex_spirv_size, 0);
  if (metadata == nullptr) {
    SDL_Log("Failed to reflect shader '%s': %s", path.data(), SDL_GetError());
    SDL_free(spirv);
    return nullptr;
  }

  SDL_GPUShader* shader = SDL_ShaderCross_CompileGraphicsShaderFromSPIRV(
      gpu, &info, &metadata->resource_info, 0);

  SDL_free(metadata);
  SDL_free(spirv);

  return shader;
}

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

  SDL_GPUShader* vertex_shader =
      load_shader(gpu_, "assets/shaders/quad.vs.hlsl", "VSMain",
                  SDL_SHADERCROSS_SHADERSTAGE_VERTEX);
  SDL_GPUShader* fragment_shader =
      load_shader(gpu_, "assets/shaders/quad.fs.hlsl", "PSMain",
                  SDL_SHADERCROSS_SHADERSTAGE_FRAGMENT);

  if (!vertex_shader || !fragment_shader) {
    SDL_Log("Shader creation failed");
    return SDL_APP_FAILURE;
  }

  // create the graphics pipeline
  SDL_GPUGraphicsPipelineCreateInfo pipeline_info{};
  pipeline_info.vertex_shader = vertex_shader;
  pipeline_info.fragment_shader = fragment_shader;
  pipeline_info.primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST;

  // describe the vertex buffers
  SDL_GPUVertexBufferDescription vertex_buffer_desctiptions[1];
  vertex_buffer_desctiptions[0].slot = 0;
  vertex_buffer_desctiptions[0].input_rate = SDL_GPU_VERTEXINPUTRATE_VERTEX;
  vertex_buffer_desctiptions[0].instance_step_rate = 0;
  vertex_buffer_desctiptions[0].pitch = sizeof(Vertex);

  pipeline_info.vertex_input_state.num_vertex_buffers = 1;
  pipeline_info.vertex_input_state.vertex_buffer_descriptions =
      vertex_buffer_desctiptions;

  // describe the vertex attribute
  SDL_GPUVertexAttribute vertex_attributes[2];

  // a_position
  vertex_attributes[0].buffer_slot = 0;
  vertex_attributes[0].location = 0;
  vertex_attributes[0].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3;
  vertex_attributes[0].offset = 0;

  // a_color
  vertex_attributes[1].buffer_slot = 0;
  vertex_attributes[1].location = 1;
  vertex_attributes[1].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4;
  vertex_attributes[1].offset = sizeof(float) * 3;

  pipeline_info.vertex_input_state.num_vertex_attributes = 2;
  pipeline_info.vertex_input_state.vertex_attributes = vertex_attributes;

  // describe the color target
  SDL_GPUColorTargetDescription color_target_descriptions[1];
  color_target_descriptions[0] = {};
  color_target_descriptions[0].blend_state.enable_blend = true;
  color_target_descriptions[0].blend_state.color_blend_op = SDL_GPU_BLENDOP_ADD;
  color_target_descriptions[0].blend_state.alpha_blend_op = SDL_GPU_BLENDOP_ADD;
  color_target_descriptions[0].blend_state.src_color_blendfactor =
      SDL_GPU_BLENDFACTOR_SRC_ALPHA;
  color_target_descriptions[0].blend_state.dst_color_blendfactor =
      SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA;
  color_target_descriptions[0].blend_state.src_alpha_blendfactor =
      SDL_GPU_BLENDFACTOR_SRC_ALPHA;
  color_target_descriptions[0].blend_state.dst_alpha_blendfactor =
      SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA;
  color_target_descriptions[0].format =
      SDL_GetGPUSwapchainTextureFormat(gpu_, window_);

  pipeline_info.target_info.num_color_targets = 1;
  pipeline_info.target_info.color_target_descriptions =
      color_target_descriptions;

  // create the pipeline
  graphics_pipeline_ = SDL_CreateGPUGraphicsPipeline(gpu_, &pipeline_info);
  if (graphics_pipeline_ == nullptr) {
    SDL_Log("Failed to create graphics pipeline: %s", SDL_GetError());
    SDL_ReleaseGPUShader(gpu_, vertex_shader);
    SDL_ReleaseGPUShader(gpu_, fragment_shader);
    return SDL_APP_FAILURE;
  }

  // we don't need to store the shaders after creating the pipeline
  SDL_ReleaseGPUShader(gpu_, vertex_shader);
  SDL_ReleaseGPUShader(gpu_, fragment_shader);

  // create the vertex buffer
  SDL_GPUBufferCreateInfo buffer_info = {};
  buffer_info.size = sizeof(vertices);
  buffer_info.usage = SDL_GPU_BUFFERUSAGE_VERTEX;
  vertex_buffer_ = SDL_CreateGPUBuffer(gpu_, &buffer_info);
  if (vertex_buffer_ == nullptr) {
    SDL_Log("Failed to create vertex buffer: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  // create a transfer buffer to upload to the vertex buffer
  SDL_GPUTransferBufferCreateInfo transfer_info = {};
  transfer_info.size = sizeof(vertices);
  transfer_info.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
  transfer_buffer_ = SDL_CreateGPUTransferBuffer(gpu_, &transfer_info);
  if (transfer_buffer_ == nullptr) {
    SDL_Log("Failed to create transfer buffer: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  // fill the transfer buffer
  Vertex* data =
      (Vertex*)SDL_MapGPUTransferBuffer(gpu_, transfer_buffer_, false);
  if (data == nullptr) {
    SDL_Log("Failed to map transfer buffer: %s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_memcpy(data, (void*)vertices, sizeof(vertices));

  SDL_UnmapGPUTransferBuffer(gpu_, transfer_buffer_);

  // start a copy pass
  SDL_GPUCommandBuffer* command_buffer = SDL_AcquireGPUCommandBuffer(gpu_);
  SDL_GPUCopyPass* copy_pass = SDL_BeginGPUCopyPass(command_buffer);

  // where is the data
  SDL_GPUTransferBufferLocation location = {};
  location.transfer_buffer = transfer_buffer_;
  location.offset = 0;

  // where to upload the data
  SDL_GPUBufferRegion region = {};
  region.buffer = vertex_buffer_;
  region.size = sizeof(vertices);
  region.offset = 0;

  // upload the data
  SDL_UploadToGPUBuffer(copy_pass, &location, &region, true);

  // end the copy pass
  SDL_EndGPUCopyPass(copy_pass);
  SDL_SubmitGPUCommandBuffer(command_buffer);

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

    // bind the pipeline
    SDL_BindGPUGraphicsPipeline(render_pass, graphics_pipeline_);

    // bind the vertex buffer
    SDL_GPUBufferBinding buffer_bindings[1];
    buffer_bindings[0].buffer =
        vertex_buffer_;             // index 0 is slot 0 in this example
    buffer_bindings[0].offset = 0;  // start from the first byte

    SDL_BindGPUVertexBuffers(render_pass, 0, buffer_bindings,
                             1);  // bind one buffer starting from slot 0

    // issue a draw call
    SDL_DrawGPUPrimitives(render_pass, 3, 1, 0, 0);

    SDL_EndGPURenderPass(render_pass);
  }

  SDL_SubmitGPUCommandBuffer(command_buffer);
  return SDL_APP_CONTINUE;
}

SDL_AppResult App::event(SDL_Event* event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }

  if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
    return SDL_APP_SUCCESS;
  }

  return SDL_APP_CONTINUE;
}

void App::draw_quad(glm::vec2 position, glm::vec2 size, glm::vec4 color) {}

}  // namespace wr