#pragma once

#include "WaveRush/Entity/EntityManager.hpp"
#include "WaveRush/GUI/WidgetManager.hpp"
#include <SDL.h>

class Scene {
private:
	EntityManager m_EntityManager;
	WidgetManager m_WidgetManager;

public:
	EntityManager& GetEntityManager();

	WidgetManager& GetWidgetManager();

	virtual void ProcessEvents(SDL_Event& p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);
};