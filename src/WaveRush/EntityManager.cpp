#include "WaveRush/EntityManager.hpp"

#include "WaveRush/Entity.hpp"

namespace WaveRush {

auto EntityManager::GetEntities() -> auto& {
    return m_entities;
}

auto EntityManager::Update(Game& game) -> void {
    for (auto& entity : m_entities)
        entity->Update(game);
}

auto EntityManager::Render() -> void {
    for (auto& entity : m_entities)
        entity->Render();
}

} // namespace WaveRush
