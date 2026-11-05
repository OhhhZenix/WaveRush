#pragma once

#include <cstddef>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace wr {

  using ComponentPool = std::tuple<std::vector<int>>;

  template <typename Tuple, std::size_t... Is>
  void reserve_tuple(Tuple& tuple, std::size_t capacity, std::index_sequence<Is...>) {
    (std::get<Is>(tuple).reserve(capacity), ...);
  }

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
