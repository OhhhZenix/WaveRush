#include "SmartEnemyMovementSystem.hpp"

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
					auto f_CurrentDistance = Distance(f_PositionSearch.Value.x, f_PositionSearch.Value.y, f_Position
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
			auto f_Distance = Distance(f_PlayerPosition.Value.x, f_PlayerPosition.Value.y, f_Position
				.Value.x, f_Position.Value.y);
			printf("Distance %f\n", f_Distance);
			printf("LerpX: %f, LerpY: %f\n", LerpValue(f_Position.Value.x, f_PlayerPosition.Value.x,
				f_Velocity.Value.x * f_Distance * p_DeltaTime), LerpValue(f_Position.Value.y, f_PlayerPosition.Value.y,
				f_Velocity.Value.y * f_Distance * p_DeltaTime));
			f_Position.Value.x = LerpValue(f_Position.Value.x, f_PlayerPosition.Value.x,
				f_Velocity.Value.x * f_Distance * p_DeltaTime);
			f_Position.Value.y = LerpValue(f_Position.Value.y, f_PlayerPosition.Value.y,
				f_Velocity.Value.y * f_Distance * p_DeltaTime);
		}
	}
}
