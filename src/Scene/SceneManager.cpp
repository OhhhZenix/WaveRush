#include "SceneManager.hpp"

SceneManager::SceneManager() {
	m_ActiveScene = nullptr;
}

SceneManager::~SceneManager() {
	delete m_ActiveScene;
}

Scene& SceneManager::GetActiveScene() {
	return *m_ActiveScene;
}

void SceneManager::SetActiveScene(Scene* p_NewScene) {
	m_ActiveScene = p_NewScene;
}