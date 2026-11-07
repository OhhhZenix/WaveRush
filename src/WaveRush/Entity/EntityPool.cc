#include "WaveRush/Entity/EntityPool.h"

#include "WaveRush/Constant.h"

#include <tuple>
#include <vector>

namespace wr {

  auto EntityPool::Instance() -> EntityPool& {
    static EntityPool pool(wr::MAX_ENTITIES);
    return pool;
  }

  template <typename T> auto EntityPool::hasComponent() -> bool { return false; }

  template <typename T> auto EntityPool::getComponent() -> T& { return {}; }

  EntityPool::EntityPool(std::size_t max_entities) : max_entities_(max_entities), num_entities_(0) {
    std::apply([max_entities](auto&... vec) { (vec.reserve(max_entities), ...); }, components_);
    generation_.reserve(max_entities);
    tags_.reserve(max_entities);
    alive_.reserve(max_entities);
  }

} // namespace wr
