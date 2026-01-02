#include "WaveRush/EntityManager.hpp"

namespace WaveRush {

EntityList& EntityManager::GetEntities() {
    return this->entities;
}

void EntityManager::Update(Game& game) {
    for (auto& entity : this->entities) {}
}

void EntityManager::Render() {
    for (auto& entity : this->entities) {}
}

} // namespace WaveRush
