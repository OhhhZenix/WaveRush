#include "WaveRush/SceneManager.hpp"

#include <stdexcept>

#include "WaveRush/Scene.hpp"

namespace WaveRush {

auto SceneManager::HasScenes() const -> bool {
    return !this->scenes.empty();
}

auto SceneManager::GetCurrentScene() -> Scene& {
    if (this->scenes.empty())
        throw std::runtime_error("SceneManager has no current scene");
    return *this->scenes.top();
}

auto SceneManager::GotoPreviousScene() -> void {
    if (this->scenes.size() <= 1)
        return;
    this->scenes.pop();
}

auto SceneManager::GotoNextScene(Scene* scene) -> void {
    this->scenes.emplace(scene);
}

auto SceneManager::Update(Game& game) -> void {
    if (this->HasScenes())
        this->scenes.top()->Update(game);
}

auto SceneManager::Render() -> void {
    if (this->HasScenes())
        this->scenes.top()->Render();
}

} // namespace WaveRush
