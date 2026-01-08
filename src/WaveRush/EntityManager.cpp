#include "WaveRush/EntityManager.hpp"

#include "WaveRush/Entity.hpp"

namespace WaveRush {

auto EntityManager::GetEntities() -> EntityManager::EntityList& {
    return this->entities;
}

auto EntityManager::AddEntity(Entity* entity) -> void {
    this->entities.emplace_back(entity);
}

auto EntityManager::Update(Game& game) -> void {
    for (auto& entity : this->entities)
        entity->Update(game);
}

auto EntityManager::Render() -> void {
    for (auto& entity : this->entities)
        entity->Render();
}

} // namespace WaveRush
