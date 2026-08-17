#pragma once

#include <cstdint>
#include <glm/glm.hpp>

#include "WaveRush/Core/Arena.h"

struct wr_shader {
  uint32_t program;
};

void wr_shader_init(wr_shader* shader, const char* vertex_source,
                    const char* fragment_source);

void wr_shader_from_file(wr_shader* shader, wr_arena* allocator,
                         const char* vertex_path, const char* fragment_path);

void wr_shader_cleanup(wr_shader* shader);

void wr_shader_bind(wr_shader* shader);

void wr_shader_set_bool(wr_shader* shader, const char* name, bool value);

void wr_shader_set_int(wr_shader* shader, const char* name, int value);

void wr_shader_set_float(wr_shader* shader, const char* name, float value);

void wr_shader_set_vec4(wr_shader* shader, const char* name, glm::vec4 value);