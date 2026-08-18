#include "Shader.h"

#include <SDL3/SDL.h>
#include <glad/glad.h>

#include <fstream>

namespace wr {

Shader::Shader(std::string_view vertex, std::string_view fragment) {
  this->compile(vertex, fragment);
}

Shader::Shader(const std::filesystem::path& vertex,
               const std::filesystem::path& fragment) {
  std::string vertex_source;
  std::string fragment_source;

  // Read vertex shader file
  std::ifstream vertex_file(vertex);
  if (!vertex_file.is_open()) {
    SDL_Log("Failed to open vertex shader file: %s", vertex.c_str());
    return;
  }
  vertex_source = std::string((std::istreambuf_iterator<char>(vertex_file)),
                              std::istreambuf_iterator<char>());
  vertex_file.close();

  // Read fragment shader file
  std::ifstream fragment_file(fragment);
  if (!fragment_file.is_open()) {
    SDL_Log("Failed to open fragment shader file: %s", fragment.c_str());
    return;
  }
  fragment_source = std::string((std::istreambuf_iterator<char>(fragment_file)),
                                std::istreambuf_iterator<char>());
  fragment_file.close();

  this->compile(vertex_source, fragment_source);
}

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
void Shader::compile(std::string_view vertex_source,
                     std::string_view fragment_source) {
  auto compile_shader = [](GLenum type, std::string_view source) -> GLuint {
    const GLuint shader = glCreateShader(type);
    const GLchar* source_ptr = source.data();
    const GLint source_length = static_cast<GLint>(source.size());

    glShaderSource(shader, 1, &source_ptr, &source_length);
    glCompileShader(shader);

    GLint success = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (success == GL_TRUE) {
      return shader;
    }

    GLint log_length = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);

    std::string log(static_cast<std::size_t>(log_length), '\0');

    if (log_length > 0) {
      glGetShaderInfoLog(shader, log_length, nullptr, log.data());
    }

    const char* shader_type = type == GL_VERTEX_SHADER ? "vertex" : "fragment";

    SDL_Log("%s shader compilation failed:\n%s", shader_type, log.c_str());

    glDeleteShader(shader);
    return 0;
  };

  const GLuint vertex_shader = compile_shader(GL_VERTEX_SHADER, vertex_source);
  if (vertex_shader == 0) {
    return;
  }

  const GLuint fragment_shader =
      compile_shader(GL_FRAGMENT_SHADER, fragment_source);
  if (fragment_shader == 0) {
    glDeleteShader(vertex_shader);
    return;
  }

  const GLuint program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);

  GLint success = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &success);

  if (success != GL_TRUE) {
    GLint log_length = 0;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);

    std::string log(static_cast<std::size_t>(log_length), '\0');

    if (log_length > 0) {
      glGetProgramInfoLog(program, log_length, nullptr, log.data());
    }

    SDL_Log("Shader program linking failed:\n%s", log.c_str());

    glDeleteProgram(program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    return;
  }

  // Shaders can be deleted after a successful link.
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  id_ = program;
}

}  // namespace wr