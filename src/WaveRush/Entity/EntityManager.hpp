#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <queue>
#include <vector>

namespace WaveRush {

struct IComponent {
    bool exists = false;
};

struct CPosition: public IComponent {
    float x = 0;
    float y = 0;
};

enum EntityTag {
    Nil,
    Player,
};

struct CTag: public IComponent {
    EntityTag value;
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
    auto CreateEntity() -> EntityHandle;
    auto IsValid(EntityHandle handle) -> bool;
    auto DeleteEntity(EntityHandle handle) -> void;
    auto GetActiveEntities() -> std::vector<EntityHandle>&;

    auto GetPosition(EntityHandle handle) -> CPosition& {
        assert(IsValid(handle) && "Invalid entity");
        return positions_[handle.index];
    }

    auto GetTag(EntityHandle handle) -> CTag& {
        assert(IsValid(handle) && "Invalid entity");
        return tags_[handle.index];
    }

  private:
    std::vector<EntityHandle> active_handles_;
    std::queue<EntityId> free_ids_;
    std::vector<EntityGen> generations_;
    std::vector<CPosition> positions_;
    std::vector<CTag> tags_;
    size_t max_entities_;
};

} // namespace WaveRush
