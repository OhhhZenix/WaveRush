#include "WaveRush/Entity/EntityManager.hpp"

namespace WaveRush {

EntityManager::EntityManager(size_t max_entities) {
    max_entities_ = max_entities;

    for (size_t i = 0; i < max_entities; i++) {
        ids_.push(i);
        generations_[i] = 0;
        alive_[i] = false;
    }
}

auto EntityManager::createEntity() -> std::optional<EntityHandle> {
    if (!ids_.empty()) {
        EntityId id = ids_.front();
        alive_[id] = true;
        ids_.pop();
        return EntityHandle {id, generations_[id]};
    }
    return std::nullopt;
}

auto EntityManager::isValid(EntityHandle handle) -> bool {
    return handle.index < max_entities_
        && handle.generations == generations_[handle.index]
        && alive_[handle.index];
}

auto EntityManager::deleteEntity(EntityHandle handle) -> void {
    if (isValid(handle)) {
        alive_[handle.index] = false;
        generations_[handle.index] += 1;
        ids_.push(handle.index);
    }
}

} // namespace WaveRush
