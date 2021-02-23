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

	virtual void ProcessUpdate(float p_DeltaTime);
};