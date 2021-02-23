#pragma once

#include <vector>
#include "system/System.hpp"

class SystemManager
{
 private:
	std::vector<System*> m_Systems;

 public:
	~SystemManager();

	void ProcessEvents(SDL_Event& p_Event, entt::registry& p_Registry);

	void ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry);

	void ProcessRender(SDL_Renderer* p_Renderer, entt::registry& p_Registry);

	void RegisterSystem(System* p_System);
};