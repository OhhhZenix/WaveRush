#include "WaveRush/SceneManager.hpp"

#include <stdexcept>

#include "WaveRush/Scene.hpp"

namespace WaveRush {

auto SceneManager::HasScenes() const -> bool {
    return !m_scenes.empty();
}

auto SceneManager::GetCurrentScene() -> Scene& {
    if (m_scenes.empty())
        throw std::runtime_error("SceneManager has no current scene");
    return *m_scenes.top();
}

auto SceneManager::GotoPreviousScene() -> void {
    if (m_scenes.size() <= 1)
        return;
    m_scenes.pop();
}

auto SceneManager::GotoNextScene(Scene* scene) -> void {
    m_scenes.emplace(scene);
}

auto SceneManager::Update(Game& game) -> void {
    if (HasScenes())
        m_scenes.top()->Update(game);
}

auto SceneManager::Render() -> void {
    if (HasScenes())
        m_scenes.top()->Render();
}

} // namespace WaveRush
