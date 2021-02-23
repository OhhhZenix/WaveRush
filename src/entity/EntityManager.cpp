#include "EntityManager.hpp"

#include <SDL.h>
#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"

entt::registry& EntityManager::GetRegistry()
{
	return m_Registry;
}

entt::entity EntityManager::CreateEntity()
{
	return m_Registry.create();
}

void EntityManager::SpawnPlayer(int32_t p_Amount)
{
	for (size_t i = 0; i < p_Amount; ++i)
	{
		auto player = CreateEntity();

		// This make sure the entity we are creating is going to be a playerw
		m_Registry.emplace<TagComponent>(player, TagType::Player);

		// This make sure it gets displayed on the screen
		m_Registry.emplace<RectangleShapeComponent>(player, SDL_Color{ 0, 255, 0, 255 }, glm::vec2(50, 50), SDL_Color{ 0, 0, 0,255 }, (int)5);

		// This allows us to know where the player is
		m_Registry.emplace<PositionComponent>(player, 100.0f, 100.0f);

		// This allows us to determine how fast the will move
		m_Registry.emplace<VelocityComponent>(player, glm::vec2(600, 600));
	}
}