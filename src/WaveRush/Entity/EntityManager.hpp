#pragma once

#include <cstddef>
#include <cstdint>
#include <optional>
#include <queue>
#include <vector>

namespace WaveRush {

struct IComponent {
    bool exists = false;
};

struct CPosition: IComponent {
    float x = 0;
    float y = 0;
};

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
    auto getActiveEntities() -> std::vector<EntityId>&;

    auto getPosition(EntityId entity) -> CPosition& {
        return positions_[entity];
    }

  private:
    std::queue<EntityId> free_ids_;
    std::vector<EntityId> used_ids_;
    std::vector<EntityGen> generations_;
    std::vector<CPosition> positions_;
    size_t max_entities_;
};

} // namespace WaveRush
