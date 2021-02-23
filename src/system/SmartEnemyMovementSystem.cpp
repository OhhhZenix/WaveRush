#include "SmartEnemyMovementSystem.hpp"

<<<<<<< HEAD
#include "core/Utils.hpp"
#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"

void SmartEnemyMovementSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<const TagComponent, RectangleShapeComponent, PositionComponent>();
	f_View
		.each([p_DeltaTime, f_View](const TagComponent& f_Tag, RectangleShapeComponent& f_RectShape, PositionComponent& f_Position)
		{
			// Checks to make sure it is some sort of smart enemy entity
			if (f_Tag.Value != TagType::SmartEnemy)
				return;

			// Lerp to player position
			{
				f_View.each([&](const TagComponent& f_Tag2, RectangleShapeComponent& f_RectShape2, PositionComponent& f_Position2)
				{
					// Some variables for tweaking.
					float atraction = 0.001; // Velocity torward the players. 
					float repulsion = -0.005; // To separate from other Smart Enemies (Must be negative). 

					if (f_Tag2.Value == TagType::Player)
					{
						f_Position.Value = glm::vec2(
							LerpValue(f_Position.Value.x, f_Position2.Value.x, atraction),
							LerpValue(f_Position.Value.y, f_Position2.Value.y, atraction)
						);
					}

					else if (f_Tag2.Value == TagType::SmartEnemy)
					{
						if (DistanceVec2(f_Position.Value, f_Position2.Value) < 100) 
						{
							f_Position.Value = glm::vec2(
								LerpValue(f_Position.Value.x, f_Position2.Value.x, repulsion),
								LerpValue(f_Position.Value.y, f_Position2.Value.y, repulsion)
							);
						}
					}
				});
			}
		}
	);
=======
#include <limits>
#include <cmath>
#include "core/Utils.hpp"
#include "component/TagComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"

void SmartEnemyMovementSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<const TagComponent, PositionComponent, VelocityComponent>();
	auto f_ViewSearch = p_Registry.view<const TagComponent, PositionComponent>();

	for (auto f_Enemy : f_View)
	{
		auto& f_Tag = f_View.get<const TagComponent>(f_Enemy);
		auto& f_Position = f_View.get<PositionComponent>(f_Enemy);

		// If not smart enemy go to the next entity
		if (f_Tag.Value != TagType::SmartEnemy)
			continue;

		entt::entity f_Player = entt::null;
		// Find the nearest player
		{
			bool f_Search = false;
			while (!f_Search)
			{
				float f_LastDistance = std::numeric_limits<float>::max();
				for (auto f_Entity : f_ViewSearch)
				{
					auto& f_TagSearch = f_ViewSearch.get<const TagComponent>(f_Entity);

					// If not a player go to the next entity
					if (f_TagSearch.Value != TagType::Player)
						continue;

					auto& f_PositionSearch = f_ViewSearch.get<PositionComponent>(f_Entity);

					// Calculates the distance from player to enemy;
					auto f_CurrentDistance = Distance2D(f_PositionSearch.Value.x, f_PositionSearch.Value.y, f_Position
						.Value.x, f_Position.Value.y);

					// If less or equal change the target
					if (f_CurrentDistance <= f_LastDistance)
					{
						f_Player = f_Entity;
						f_LastDistance = f_CurrentDistance;
					}
				}
				f_Search = true;
			}
		}

		// If no player found exit
		if (f_Player == entt::null)
			break;

		// Make movement
		{
			auto& f_PlayerPosition = f_ViewSearch.get<PositionComponent>(f_Player);
			auto& f_Velocity = f_View.get<VelocityComponent>(f_Enemy);
			auto f_Distance = Distance2D(f_PlayerPosition.Value.x, f_PlayerPosition.Value.y, f_Position
				.Value.x, f_Position.Value.y);
			f_Position.Value.x = LerpValue(f_Position.Value.x, f_PlayerPosition.Value.x,
				f_Velocity.Value.x * f_Distance * p_DeltaTime);
			f_Position.Value.y = LerpValue(f_Position.Value.y, f_PlayerPosition.Value.y,
				f_Velocity.Value.y * f_Distance * p_DeltaTime);
		}
	}
>>>>>>> 91c8cf1389fccfa165001dcd35a0990a00161306
}
