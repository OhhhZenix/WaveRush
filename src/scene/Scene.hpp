#pragma once

#include "system/SystemManager.hpp"
#include "entity/EntityManager.hpp"

class Scene
{
 private:
	SystemManager m_SystemManager;
	EntityManager m_EntityManager;

 public:
	SystemManager& GetSystemManager();

	EntityManager& GetEntityManager();

	virtual void ProcessEvents(SDL_Event* p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);
};