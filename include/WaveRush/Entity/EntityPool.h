#pragma once

#include <cstddef>
#include <string>
#include <tuple>
#include <vector>

namespace wr {

  using ComponentPool = std::tuple<std::vector<int>>;

  class EntityPool {
  public:
    static EntityPool& Instance();
    template <typename T> bool hasComponent();
    template <typename T> T& getComponent();

  private:
    std::size_t max_entities_;
    std::size_t num_entities_;
    std::vector<bool> alive_;
    std::vector<std::string> tags_;
    ComponentPool components_;

    EntityPool(std::size_t max_entities);
  };

} // namespace wr
