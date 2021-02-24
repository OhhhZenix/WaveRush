#pragma once

#include <entt/entt.hpp>
#include <SDL.h>

class EntityManager
{
 private:
	entt::registry m_Registry;

 public:
	entt::registry& GetRegistry();

	entt::entity CreateEntity();

	void SpawnPlayer(int32_t p_Amount);

	void SpawnBasicEnemy(int32_t p_Amount);

	void SpawnSmartEnemy(int32_t p_Amount);

	void SpawnParticleSystem(uint32_t p_MaxParticles, float p_MaxLifetime, float p_MaxVelocity, SDL_Color p_Color);
};