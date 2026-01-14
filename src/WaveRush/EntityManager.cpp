#include "WaveRush/EntityManager.hpp"

#include "WaveRush/Entity.hpp"

namespace WaveRush {

auto EntityManager::GetEntities() -> auto& {
    return entities_;
}

auto EntityManager::Update(Game& game) -> void {
    for (auto& entity : entities_)
        entity->Update(game);
}

auto EntityManager::Render() -> void {
    for (auto& entity : entities_)
        entity->Render();
}

} // namespace WaveRush
