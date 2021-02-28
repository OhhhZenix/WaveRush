#pragma once

#include "Entity/EntityManager.hpp"

class Scene
{
 private:
	EntityManager m_EntityManager;

 public:
	EntityManager& GetEntityManager();

	virtual void ProcessEvents(SDL_Event& p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);
};