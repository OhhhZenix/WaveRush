#pragma once

#include <vector>

#include "Entity.hpp"

class EntityManager
{
 private:
	std::vector<Entity*> m_Entities;

 public:
	~EntityManager();

	void ProcessEvent(SDL_Event* p_Event);

	void ProcessUpdate(float p_DeltaTime);

	void ProcessRender(SDL_Renderer* p_Renderer);

	void Spawn(EntityType p_EntityType, uint32_t p_Amount);

	std::vector<Entity*> GetAllEntityWith(EntityType p_EntityType);
};