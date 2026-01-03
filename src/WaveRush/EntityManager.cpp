#include "WaveRush/EntityManager.hpp"

#include "WaveRush/Entity.hpp"

namespace WaveRush {

EntityList& EntityManager::GetEntities() {
    return this->entities;
}

void EntityManager::AddEntity(Entity* entity) {
    this->entities.emplace_back(entity);
}

void EntityManager::Update(Game& game) {
    for (auto& entity : this->entities)
        entity->Update(game);
}

void EntityManager::Render() {
    for (auto& entity : this->entities)
        entity->Render();
}

} // namespace WaveRush
