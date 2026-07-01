#include "Game.h"

#include <SDL3_shadercross/SDL_shadercross.h>

#include <cstdint>

#include "WaveRush/Core/Arena.h"
#include "WaveRush/Entity/World.h"

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

  game->gpu = SDL_CreateGPUDevice(SDL_ShaderCross_GetSPIRVShaderFormats(),
                                  false, nullptr);

  if (game->gpu == nullptr) {
    SDL_Log("Failed to create GPU device: %s", SDL_GetError());
    return;
  }

  if (SDL_ClaimWindowForGPUDevice(game->gpu, game->window) == false) {
    SDL_Log("Failed to claim window: %s", SDL_GetError());
    return;
  }

  SDL_Log("%s", SDL_GetGPUDeviceDriver(game->gpu));

  // load the vertex shader code
  size_t vertex_source_size = 0;
  char* vertex_source =
      (char*)SDL_LoadFile("assets/shaders/vertex.hlsl", &vertex_source_size);

  // Describe the HLSL shader
  SDL_ShaderCross_HLSL_Info vertex_hlsl{};
  vertex_hlsl.source = vertex_source;
  vertex_hlsl.entrypoint = "VSMain";
  vertex_hlsl.shader_stage = SDL_SHADERCROSS_SHADERSTAGE_VERTEX;

  // Compile HLSL -> SPIR-V
  size_t vertex_spirv_size = 0;
  void* vertex_spirv =
      SDL_ShaderCross_CompileSPIRVFromHLSL(&vertex_hlsl, &vertex_spirv_size);

  // SPIR-V info
  SDL_ShaderCross_SPIRV_Info vertex_info{};
  vertex_info.bytecode = (Uint8*)vertex_spirv;
  vertex_info.bytecode_size = vertex_spirv_size;
  vertex_info.entrypoint = "VSMain";
  vertex_info.shader_stage = SDL_SHADERCROSS_SHADERSTAGE_VERTEX;

  // Reflect
  SDL_ShaderCross_GraphicsShaderMetadata* vertex_metadata =
      SDL_ShaderCross_ReflectGraphicsSPIRV((Uint8*)vertex_spirv,
                                           vertex_spirv_size, 0);

  // Create GPU shader
  SDL_GPUShader* vertex_shader = SDL_ShaderCross_CompileGraphicsShaderFromSPIRV(
      game->gpu, &vertex_info, &vertex_metadata->resource_info, 0);

  SDL_free(vertex_metadata);
  SDL_free(vertex_spirv);
  SDL_free(vertex_source);

  // load the fragment shader code
  size_t fragment_source_size = 0;
  char* fragment_source = (char*)SDL_LoadFile("assets/shaders/fragment.hlsl",
                                              &fragment_source_size);

  SDL_ShaderCross_HLSL_Info fragment_hlsl{};
  fragment_hlsl.source = fragment_source;
  fragment_hlsl.entrypoint = "PSMain";
  fragment_hlsl.shader_stage = SDL_SHADERCROSS_SHADERSTAGE_FRAGMENT;

  size_t fragment_spirv_size = 0;
  void* fragment_spirv = SDL_ShaderCross_CompileSPIRVFromHLSL(
      &fragment_hlsl, &fragment_spirv_size);

  SDL_ShaderCross_SPIRV_Info fragment_info{};
  fragment_info.bytecode = (Uint8*)fragment_spirv;
  fragment_info.bytecode_size = fragment_spirv_size;
  fragment_info.entrypoint = "PSMain";
  fragment_info.shader_stage = SDL_SHADERCROSS_SHADERSTAGE_FRAGMENT;

  SDL_ShaderCross_GraphicsShaderMetadata* fragment_metadata =
      SDL_ShaderCross_ReflectGraphicsSPIRV((Uint8*)fragment_spirv,
                                           fragment_spirv_size, 0);

  SDL_GPUShader* fragment_shader =
      SDL_ShaderCross_CompileGraphicsShaderFromSPIRV(
          game->gpu, &fragment_info, &fragment_metadata->resource_info, 0);

  SDL_free(fragment_metadata);
  SDL_free(fragment_spirv);
  SDL_free(fragment_source);

  if (!vertex_shader || !fragment_shader) {
    SDL_Log("Shader creation failed");
    return;
  }

  SDL_Log("VS: %p FS: %p", vertex_shader, fragment_shader);

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
      SDL_GetGPUSwapchainTextureFormat(game->gpu, game->window);

  pipeline_info.target_info.num_color_targets = 1;
  pipeline_info.target_info.color_target_descriptions =
      color_target_descriptions;

  // create the pipeline
  game->graphics_pipeline =
      SDL_CreateGPUGraphicsPipeline(game->gpu, &pipeline_info);

  // we don't need to store the shaders after creating the pipeline
  SDL_ReleaseGPUShader(game->gpu, vertex_shader);
  SDL_ReleaseGPUShader(game->gpu, fragment_shader);

  // create the vertex buffer
  SDL_GPUBufferCreateInfo buffer_info = {};
  buffer_info.size = sizeof(vertices);
  buffer_info.usage = SDL_GPU_BUFFERUSAGE_VERTEX;
  game->vertex_buffer = SDL_CreateGPUBuffer(game->gpu, &buffer_info);

  // create a transfer buffer to upload to the vertex buffer
  SDL_GPUTransferBufferCreateInfo transfer_info = {};
  transfer_info.size = sizeof(vertices);
  transfer_info.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
  game->transfer_buffer =
      SDL_CreateGPUTransferBuffer(game->gpu, &transfer_info);

  // fill the transfer buffer
  Vertex* data = (Vertex*)SDL_MapGPUTransferBuffer(
      game->gpu, game->transfer_buffer, false);

  SDL_memcpy(data, (void*)vertices, sizeof(vertices));

  SDL_UnmapGPUTransferBuffer(game->gpu, game->transfer_buffer);

  // start a copy pass
  SDL_GPUCommandBuffer* command_buffer = SDL_AcquireGPUCommandBuffer(game->gpu);
  SDL_GPUCopyPass* copy_pass = SDL_BeginGPUCopyPass(command_buffer);

  // where is the data
  SDL_GPUTransferBufferLocation location = {};
  location.transfer_buffer = game->transfer_buffer;
  location.offset = 0;

  // where to upload the data
  SDL_GPUBufferRegion region = {};
  region.buffer = game->vertex_buffer;
  region.size = sizeof(vertices);
  region.offset = 0;

  // upload the data
  SDL_UploadToGPUBuffer(copy_pass, &location, &region, true);

  // end the copy pass
  SDL_EndGPUCopyPass(copy_pass);
  SDL_SubmitGPUCommandBuffer(command_buffer);

  // game
  wr_arena_init(&game->arena, 1024 * 1024);
  wr_world_init(&game->world, &game->arena, 1024);
  game->running = true;
}

void wr_game_cleanup(wr_game* game) {
  SDL_ReleaseGPUBuffer(game->gpu, game->vertex_buffer);
  SDL_ReleaseGPUTransferBuffer(game->gpu, game->transfer_buffer);
  SDL_ReleaseGPUGraphicsPipeline(game->gpu, game->graphics_pipeline);
  // SDL_ReleaseWindowFromGPUDevice(game->gpu, game->window);
  SDL_DestroyGPUDevice(game->gpu);
  SDL_DestroyWindow(game->window);
  SDL_Quit();
}

void wr_game_run(wr_game* game) {
  for (size_t i = 0; i < 2000; i++) {
    wr_entity_ref ref = wr_world_add(&game->world);
    wr_entity* entity = wr_world_get(&game->world, ref);
    entity->tag = wr_entity_tag::player;
    entity->position = {1, 2, 3};
  }

  while (game->running) {
    SDL_Event event = {};
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        game->running = false;
      }
    }

    SDL_GPUCommandBuffer* command_buffer =
        SDL_AcquireGPUCommandBuffer(game->gpu);

    SDL_GPUTexture* swapchain_texture = nullptr;
    uint32_t width = 0;
    uint32_t height = 0;
    SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, game->window,
                                          &swapchain_texture, &width, &height);

    if (swapchain_texture) {
      SDL_GPUColorTargetInfo color_target = {};
      color_target.texture = swapchain_texture;
      color_target.clear_color.r = 0.1f;
      color_target.clear_color.g = 0.2f;
      color_target.clear_color.b = 0.4f;
      color_target.clear_color.a = 1.0f;
      color_target.load_op = SDL_GPU_LOADOP_CLEAR;
      color_target.store_op = SDL_GPU_STOREOP_STORE;

      SDL_GPURenderPass* render_pass =
          SDL_BeginGPURenderPass(command_buffer, &color_target, 1, nullptr);

      // bind the pipeline
      SDL_BindGPUGraphicsPipeline(render_pass, game->graphics_pipeline);

      // bind the vertex buffer
      SDL_GPUBufferBinding buffer_bindings[1];
      buffer_bindings[0].buffer =
          game->vertex_buffer;        // index 0 is slot 0 in this example
      buffer_bindings[0].offset = 0;  // start from the first byte

      SDL_BindGPUVertexBuffers(render_pass, 0, buffer_bindings,
                               1);  // bind one buffer starting from slot 0

      // issue a draw call
      SDL_DrawGPUPrimitives(render_pass, 3, 1, 0, 0);

      SDL_EndGPURenderPass(render_pass);
    }

    SDL_SubmitGPUCommandBuffer(command_buffer);
  }
}
