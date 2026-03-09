#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <queue>
#include <unordered_map>

namespace WaveRush {

using EntityId = uint32_t;
using EntityGen = uint32_t;

struct EntityHandle {
    EntityId index;
    EntityGen generations;
};

class EntityManager {
  public:
    EntityManager(size_t max_entities);
    auto createEntity() -> std::optional<EntityHandle>;
    auto isValid(EntityHandle handle) -> bool;
    auto deleteEntity(EntityHandle handle) -> void;

  private:
    std::queue<EntityId> ids_;
    std::unordered_map<EntityId, EntityGen> generations_;
    std::unordered_map<EntityId, bool> alive_;
    size_t max_entities_;
};

} // namespace WaveRush
