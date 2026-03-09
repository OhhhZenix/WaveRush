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
    EntityManager(size_t max_entities) {
        max_entities_ = max_entities;

        for (size_t i = 0; i < max_entities; i++) {
            ids_.push(i);
            generations_[i] = 0;
            alive_[i] = false;
        }
    }

    auto createEntity() -> std::optional<EntityHandle> {
        if (!ids_.empty()) {
            EntityId id = ids_.front();
            alive_[id] = true;
            ids_.pop();
            return EntityHandle {id, generations_[id]};
        }
        return std::nullopt;
    }

    auto isValid(EntityHandle handle) -> bool {
        return handle.index < max_entities_
            && handle.generations == generations_[handle.index]
            && alive_[handle.index];
    }

    auto deleteEntity(EntityHandle handle) -> void {
        if (isValid(handle)) {
            alive_[handle.index] = false;
            generations_[handle.index] += 1;
            ids_.push(handle.index);
        }
    }

  private:
    std::queue<EntityId> ids_;
    std::unordered_map<EntityId, EntityGen> generations_;
    std::unordered_map<EntityId, bool> alive_;
    size_t max_entities_;
};

} // namespace WaveRush
