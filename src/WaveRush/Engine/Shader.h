#pragma once

#include <cstdint>
#include <filesystem>
#include <glm/glm.hpp>
#include <string_view>

namespace wr {

class Shader {
 public:
  explicit Shader(std::string_view vertex, std::string_view fragment);
  explicit Shader(const std::filesystem::path& vertex,
                  const std::filesystem::path& fragment);
  ~Shader();
  Shader(const Shader&) = delete;
  Shader& operator=(const Shader&) = delete;
  Shader(Shader&&) = delete;
  Shader& operator=(Shader&&) = delete;
  void bind() const;
  void unbind() const;
  void set_bool(std::string_view name, bool value) const;
  void set_int(std::string_view name, int value) const;
  void set_float(std::string_view name, float value) const;
  void set_vec4(std::string_view name, glm::vec4 value) const;

 private:
  std::uint32_t id_;
};

};  // namespace wr