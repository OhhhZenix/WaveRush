#include "EntityManager.hpp"

entt::registry& EntityManager::GetRegistry()
{
	return m_Registry;
}

entt::entity EntityManager::CreateEntity()
{
	return m_Registry.create();
}

