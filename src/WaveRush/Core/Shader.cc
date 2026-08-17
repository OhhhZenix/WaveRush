#include "Shader.h"

#include <SDL3/SDL.h>
#include <glad/glad.h>

#include <cstdio>
#include <cstdlib>

void wr_shader_init(wr_shader* shader, const char* vertex_source,
                    const char* fragment_source) {
  unsigned int vertex_shader = 0;
  unsigned int fragment_shader = 0;
  int success = 0;
  int buffer_size = 512;
  char info_log[buffer_size];

  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vertex_source, nullptr);
  glCompileShader(vertex_shader);

  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertex_shader, buffer_size, nullptr, info_log);
    SDL_Log("Vertex shader compilation failed: %s", info_log);
  }

  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fragment_source, nullptr);
  glCompileShader(fragment_shader);

  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragment_shader, buffer_size, nullptr, info_log);
    SDL_Log("Fragment shader compilation failed: %s", info_log);
  }

  shader->program = glCreateProgram();
  glAttachShader(shader->program, vertex_shader);
  glAttachShader(shader->program, fragment_shader);
  glLinkProgram(shader->program);

  glGetProgramiv(shader->program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shader->program, buffer_size, NULL, info_log);
    SDL_Log("Shader program linking failed: %s", info_log);
  }

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

char* read_file(wr_arena* allocator, const char* path) {
  FILE* file = fopen(path, "rb");
  if (!file) {
    SDL_Log("Failed to open file: %s", path);
    return NULL;
  }

  // Find file size
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  // Allocate space (+1 for '\0')
  char* buffer = (char*)wr_arena_alloc(allocator, (size_t)size + 1);
  if (!buffer) {
    fclose(file);
    return NULL;
  }

  // Read file
  size_t bytes_read = fread(buffer, 1, (size_t)size, file);
  buffer[bytes_read] = '\0';

  fclose(file);

  return buffer;
}

void wr_shader_from_file(wr_shader* shader, wr_arena* allocator,
                         const char* vertex_path, const char* fragment_path) {
  char* vertex_source = read_file(allocator, vertex_path);
  char* fragment_source = read_file(allocator, fragment_path);
  if (vertex_source && fragment_source) {
    wr_shader_init(shader, vertex_source, fragment_source);
  } else {
    SDL_Log("Failed to read shader files: %s, %s", vertex_path, fragment_path);
  }
}

void wr_shader_cleanup(wr_shader* shader) {
  glUseProgram(0);
  glDeleteProgram(shader->program);
}

void wr_shader_bind(wr_shader* shader) { glUseProgram(shader->program); }

void wr_shader_set_bool(wr_shader* shader, const char* name, bool value) {
  glUniform1i(glGetUniformLocation(shader->program, name), (int)value);
}

void wr_shader_set_int(wr_shader* shader, const char* name, int value) {
  glUniform1i(glGetUniformLocation(shader->program, name), value);
}

void wr_shader_set_float(wr_shader* shader, const char* name, float value) {
  glUniform1f(glGetUniformLocation(shader->program, name), value);
}

void wr_shader_set_vec4(wr_shader* shader, const char* name, glm::vec4 value) {
  glUniform4f(glGetUniformLocation(shader->program, name), value.x, value.y,
              value.z, value.w);
}