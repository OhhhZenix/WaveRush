#include "Game.h"

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

  // load the vertex shader code
  size_t vertexCodeSize = 0;
  void* vertexCode = SDL_LoadFile("assets/shaders/vertex.spv", &vertexCodeSize);

  // create the vertex shader
  SDL_GPUShaderCreateInfo vertexInfo = {};
  vertexInfo.code = (Uint8*)vertexCode;
  vertexInfo.code_size = vertexCodeSize;
  vertexInfo.entrypoint = "main";
  vertexInfo.format = SDL_GPU_SHADERFORMAT_SPIRV;
  vertexInfo.stage = SDL_GPU_SHADERSTAGE_VERTEX;
  vertexInfo.num_samplers = 0;
  vertexInfo.num_storage_buffers = 0;
  vertexInfo.num_storage_textures = 0;
  vertexInfo.num_uniform_buffers = 0;

  SDL_GPUShader* vertexShader = SDL_CreateGPUShader(game->gpu, &vertexInfo);

  // free the file
  SDL_free(vertexCode);

  // load the fragment shader code
  size_t fragmentCodeSize = 0;
  void* fragmentCode =
      SDL_LoadFile("assets/shaders/fragment.spv", &fragmentCodeSize);

  // create the fragment shader
  SDL_GPUShaderCreateInfo fragmentInfo = {};
  fragmentInfo.code = (Uint8*)fragmentCode;
  fragmentInfo.code_size = fragmentCodeSize;
  fragmentInfo.entrypoint = "main";
  fragmentInfo.format = SDL_GPU_SHADERFORMAT_SPIRV;
  fragmentInfo.stage = SDL_GPU_SHADERSTAGE_FRAGMENT;
  fragmentInfo.num_samplers = 0;
  fragmentInfo.num_storage_buffers = 0;
  fragmentInfo.num_storage_textures = 0;
  fragmentInfo.num_uniform_buffers = 0;

  SDL_GPUShader* fragmentShader = SDL_CreateGPUShader(game->gpu, &fragmentInfo);

  // free the file
  SDL_free(fragmentCode);

  // create the graphics pipeline
  SDL_GPUGraphicsPipelineCreateInfo pipelineInfo{};
  pipelineInfo.vertex_shader = vertexShader;
  pipelineInfo.fragment_shader = fragmentShader;
  pipelineInfo.primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST;

  // describe the vertex buffers
  SDL_GPUVertexBufferDescription vertexBufferDesctiptions[1];
  vertexBufferDesctiptions[0].slot = 0;
  vertexBufferDesctiptions[0].input_rate = SDL_GPU_VERTEXINPUTRATE_VERTEX;
  vertexBufferDesctiptions[0].instance_step_rate = 0;
  vertexBufferDesctiptions[0].pitch = sizeof(Vertex);

  pipelineInfo.vertex_input_state.num_vertex_buffers = 1;
  pipelineInfo.vertex_input_state.vertex_buffer_descriptions =
      vertexBufferDesctiptions;

  // describe the vertex attribute
  SDL_GPUVertexAttribute vertexAttributes[2];

  // a_position
  vertexAttributes[0].buffer_slot = 0;
  vertexAttributes[0].location = 0;
  vertexAttributes[0].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3;
  vertexAttributes[0].offset = 0;

  // a_color
  vertexAttributes[1].buffer_slot = 0;
  vertexAttributes[1].location = 1;
  vertexAttributes[1].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4;
  vertexAttributes[1].offset = sizeof(float) * 3;

  pipelineInfo.vertex_input_state.num_vertex_attributes = 2;
  pipelineInfo.vertex_input_state.vertex_attributes = vertexAttributes;

  // describe the color target
  SDL_GPUColorTargetDescription colorTargetDescriptions[1];
  colorTargetDescriptions[0] = {};
  colorTargetDescriptions[0].blend_state.enable_blend = true;
  colorTargetDescriptions[0].blend_state.color_blend_op = SDL_GPU_BLENDOP_ADD;
  colorTargetDescriptions[0].blend_state.alpha_blend_op = SDL_GPU_BLENDOP_ADD;
  colorTargetDescriptions[0].blend_state.src_color_blendfactor =
      SDL_GPU_BLENDFACTOR_SRC_ALPHA;
  colorTargetDescriptions[0].blend_state.dst_color_blendfactor =
      SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA;
  colorTargetDescriptions[0].blend_state.src_alpha_blendfactor =
      SDL_GPU_BLENDFACTOR_SRC_ALPHA;
  colorTargetDescriptions[0].blend_state.dst_alpha_blendfactor =
      SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA;
  colorTargetDescriptions[0].format =
      SDL_GetGPUSwapchainTextureFormat(game->gpu, game->window);

  pipelineInfo.target_info.num_color_targets = 1;
  pipelineInfo.target_info.color_target_descriptions = colorTargetDescriptions;

  // create the pipeline
  game->graphics_pipeline =
      SDL_CreateGPUGraphicsPipeline(game->gpu, &pipelineInfo);

  // we don't need to store the shaders after creating the pipeline
  SDL_ReleaseGPUShader(game->gpu, vertexShader);
  SDL_ReleaseGPUShader(game->gpu, fragmentShader);

  // create the vertex buffer
  SDL_GPUBufferCreateInfo bufferInfo = {};
  bufferInfo.size = sizeof(vertices);
  bufferInfo.usage = SDL_GPU_BUFFERUSAGE_VERTEX;
  game->vertex_buffer = SDL_CreateGPUBuffer(game->gpu, &bufferInfo);

  // create a transfer buffer to upload to the vertex buffer
  SDL_GPUTransferBufferCreateInfo transferInfo = {};
  transferInfo.size = sizeof(vertices);
  transferInfo.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
  game->transfer_buffer = SDL_CreateGPUTransferBuffer(game->gpu, &transferInfo);

  // fill the transfer buffer
  Vertex* data = (Vertex*)SDL_MapGPUTransferBuffer(
      game->gpu, game->transfer_buffer, false);

  SDL_memcpy(data, (void*)vertices, sizeof(vertices));

  SDL_UnmapGPUTransferBuffer(game->gpu, game->transfer_buffer);

  // start a copy pass
  SDL_GPUCommandBuffer* commandBuffer = SDL_AcquireGPUCommandBuffer(game->gpu);
  SDL_GPUCopyPass* copyPass = SDL_BeginGPUCopyPass(commandBuffer);

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
  SDL_UploadToGPUBuffer(copyPass, &location, &region, true);

  // end the copy pass
  SDL_EndGPUCopyPass(copyPass);
  SDL_SubmitGPUCommandBuffer(commandBuffer);

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

    SDL_GPUCommandBuffer* cmd = SDL_AcquireGPUCommandBuffer(game->gpu);

    SDL_GPUTexture* swapchainTexture = nullptr;
    uint32_t width = 0;
    uint32_t height = 0;
    SDL_WaitAndAcquireGPUSwapchainTexture(cmd, game->window, &swapchainTexture,
                                          &width, &height);

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

      // bind the pipeline
      SDL_BindGPUGraphicsPipeline(pass, game->graphics_pipeline);

      // bind the vertex buffer
      SDL_GPUBufferBinding bufferBindings[1];
      bufferBindings[0].buffer =
          game->vertex_buffer;       // index 0 is slot 0 in this example
      bufferBindings[0].offset = 0;  // start from the first byte

      SDL_BindGPUVertexBuffers(pass, 0, bufferBindings,
                               1);  // bind one buffer starting from slot 0

      // issue a draw call
      SDL_DrawGPUPrimitives(pass, 3, 1, 0, 0);

      SDL_EndGPURenderPass(pass);
    }

    SDL_SubmitGPUCommandBuffer(cmd);
  }
}
