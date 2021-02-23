#pragma once

#include <entt/entt.hpp>

class EntityManager
{
 private:
	entt::registry m_Registry;

 public:
	entt::registry& GetRegistry();

	entt::entity CreateEntity();

	void SpawnPlayer(int32_t p_Amount);
};