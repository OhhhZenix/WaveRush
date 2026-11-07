#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

namespace wr {

  using ComponentPool = std::tuple<std::vector<int>, std::vector<float>>;

  class EntityPool {
  public:
    static auto Instance() -> EntityPool&;
    template <typename T> auto hasComponent() -> bool;
    template <typename T> auto getComponent() -> T&;

  private:
    ComponentPool components_;
    std::vector<std::uint32_t> generation_;
    std::vector<std::string> tags_;
    std::vector<bool> alive_;
    std::size_t max_entities_;
    std::size_t num_entities_;

    EntityPool(std::size_t max_entities);
  };

} // namespace wr
