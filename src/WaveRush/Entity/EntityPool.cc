#include "WaveRush/Entity/EntityPool.h"

namespace wr {

  EntityPool::EntityPool(std::size_t max_entities) {
    max_entities_ = max_entities;
    num_entities_ = 0;
    alive_.reserve(max_entities);
    tags_.reserve(max_entities);
  }

} // namespace wr
