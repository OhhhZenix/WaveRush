#pragma once

#include "Core/PCH.hpp"
#include "Entity/Entity.hpp"

class EntityManager
{
 private:
	std::vector<Entity*> m_Entities;

 public:
	Entity *AddEntity(Entity *p_Entity);

	void RemoveEntity(Entity *p_Entity);

	std::vector<Entity*>& GetEntities();

	void ProcessEvents(SDL_Event& p_Event);

	void ProcessUpdate(float p_DeltaTime);

	void ProcessRender(SDL_Renderer* p_Renderer);
};