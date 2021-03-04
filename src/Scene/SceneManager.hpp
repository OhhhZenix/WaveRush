#pragma once

#include "Scene/Scene.hpp"

class SceneManager {
private:
	Scene* m_ActiveScene;

public:
	SceneManager();

	~SceneManager();

	Scene& GetActiveScene();

	void SetActiveScene(Scene* p_NewScene);
};