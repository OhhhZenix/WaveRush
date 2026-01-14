#include "WaveRush/SceneManager.hpp"

#include <stdexcept>

#include "WaveRush/Scene.hpp"

namespace WaveRush {

auto SceneManager::HasScenes() const -> bool {
    return !scenes_.empty();
}

auto SceneManager::GetCurrentScene() -> Scene& {
    if (scenes_.empty())
        throw std::runtime_error("SceneManager has no current scene");
    return *scenes_.top();
}

auto SceneManager::GotoPreviousScene() -> void {
    if (scenes_.size() <= 1)
        return;
    scenes_.pop();
}

auto SceneManager::GotoNextScene(Scene* scene) -> void {
    scenes_.emplace(scene);
}

auto SceneManager::Update(Game& game) -> void {
    if (HasScenes())
        scenes_.top()->Update(game);
}

auto SceneManager::Render() -> void {
    if (HasScenes())
        scenes_.top()->Render();
}

} // namespace WaveRush
