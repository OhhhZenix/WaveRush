#include "WaveRush/Entity/EntityManager.hpp"

#include <cassert>

namespace WaveRush {

EntityManager::EntityManager(size_t max_entities) {
    max_entities_ = max_entities;
    generations_.resize(max_entities, 0);
    positions_.resize(max_entities);
    tags_.resize(max_entities);

    for (size_t i = 0; i < max_entities; i++) {
        free_ids_.push(i);
    }
}

auto EntityManager::CreateEntity() -> EntityHandle {
    assert(!free_ids_.empty() && "Ran out of available entities");

    EntityId id = free_ids_.front();
    free_ids_.pop();

    EntityHandle handle = EntityHandle {id, generations_[id]};
    active_handles_.push_back(handle);

    return handle;
}

auto EntityManager::IsValid(EntityHandle handle) -> bool {
    return handle.index < max_entities_
        && handle.generations == generations_[handle.index];
}

auto EntityManager::DeleteEntity(EntityHandle handle) -> void {
    if (!IsValid(handle))
        return;

    generations_[handle.index] += 1;

    for (size_t i = 0; i < active_handles_.size(); i++) {
        if (active_handles_[i].index == handle.index) {
            active_handles_[i] = active_handles_.back();
            active_handles_.pop_back();
            break;
        }
    }

    free_ids_.push(handle.index);
}

auto EntityManager::GetActiveEntities() -> std::vector<EntityHandle>& {
    return active_handles_;
}

} // namespace WaveRush
