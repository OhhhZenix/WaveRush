#include "WaveRush/SceneManager.hpp"

#include <stdexcept>

#include "WaveRush/Scene.hpp"

namespace WaveRush {

bool SceneManager::HasScenes() {
    return !this->scenes.empty();
}

Scene& SceneManager::GetCurrentScene() {
    if (this->scenes.empty())
        throw std::runtime_error("SceneManager has no current scene");
    return *this->scenes.top();
}

void SceneManager::GotoPreviousScene() {
    if (this->scenes.size() <= 1)
        return;
    this->scenes.pop();
}

void SceneManager::GotoNextScene(Scene* scene) {
    this->scenes.emplace(scene);
}

} // namespace WaveRush
