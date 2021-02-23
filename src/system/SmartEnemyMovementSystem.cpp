#include "SmartEnemyMovementSystem.hpp"

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
}