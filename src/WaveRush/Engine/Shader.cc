#include "Shader.h"

#include <glad/glad.h>

namespace wr {

Shader::Shader(std::string_view vertex, std::string_view fragment) {}

Shader::Shader(const std::filesystem::path& vertex,
               const std::filesystem::path& fragment) {}

Shader::~Shader() {
  glUseProgram(0);
  glDeleteProgram(id_);
}

void Shader::bind() const { glUseProgram(id_); }

void Shader::unbind() const { glUseProgram(0); }

void Shader::set_bool(std::string_view name, bool value) const {
  glUniform1i(glGetUniformLocation(id_, name.data()), (int)value);
}

void Shader::set_float(std::string_view name, float value) const {
  glUniform1f(glGetUniformLocation(id_, name.data()), value);
}

void Shader::set_vec4(std::string_view name, glm::vec4 value) const {
  glUniform4f(glGetUniformLocation(id_, name.data()), value.x, value.y, value.z,
              value.w);
}

}  // namespace wr