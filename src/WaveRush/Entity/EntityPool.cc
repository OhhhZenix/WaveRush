#include "WaveRush/Entity/EntityPool.h"

#include "WaveRush/Constant.h"

#include <tuple>
#include <vector>

namespace wr {

  EntityPool& EntityPool::Instance() {
    static EntityPool pool(wr::MAX_ENTITIES);
    return pool;
  }

  template <typename T> bool EntityPool::hasComponent() { return false; }

  template <typename T> T& EntityPool::getComponent() { return {}; }

  EntityPool::EntityPool(std::size_t max_entities) {
    max_entities_ = max_entities;
    num_entities_ = 0;
    alive_.reserve(max_entities);
    tags_.reserve(max_entities);
    components_ = ComponentPool{};
    reserve_tuple(components_, max_entities, std::make_index_sequence<std::tuple_size_v<ComponentPool>>{});
  }

} // namespace wr
