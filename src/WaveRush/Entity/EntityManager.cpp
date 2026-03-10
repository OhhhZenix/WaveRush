#include "WaveRush/Entity/EntityManager.hpp"

namespace WaveRush {

EntityManager::EntityManager(size_t max_entities) {
    max_entities_ = max_entities;
    generations_.resize(max_entities, 0);
    positions_.resize(max_entities);

    for (size_t i = 0; i < max_entities; i++) {
        free_ids_.push(i);
    }
}

auto EntityManager::createEntity() -> std::optional<EntityHandle> {
    if (!free_ids_.empty()) {
        EntityId id = free_ids_.front();
        free_ids_.pop();
        used_ids_.push_back(id);
        return EntityHandle {id, generations_[id]};
    }
    return std::nullopt;
}

auto EntityManager::isValid(EntityHandle handle) -> bool {
    return handle.index < max_entities_
        && handle.generations == generations_[handle.index];
}

auto EntityManager::deleteEntity(EntityHandle handle) -> void {
    if (!isValid(handle))
        return;

    generations_[handle.index] += 1;

    for (size_t i = 0; i < used_ids_.size(); i++) {
        if (used_ids_[i] == handle.index) {
            used_ids_[i] = used_ids_.back();
            used_ids_.pop_back();
            break;
        }
    }

    free_ids_.push(handle.index);
}

auto EntityManager::getActiveEntities() -> std::vector<EntityId>& {
    return used_ids_;
}

} // namespace WaveRush
