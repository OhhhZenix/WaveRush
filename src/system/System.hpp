#pragma once

#include <entt/entt.hpp>
#include <SDL.h>

class System
{
 public:
	virtual ~System() = default;

	virtual void ProcessEvents(SDL_Event* p_Event, entt::registry& p_Registry);

	virtual void ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry);

	virtual void ProcessRender(SDL_Renderer* p_Renderer, entt::registry& p_Registry);
};
