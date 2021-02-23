#include "SmartEnemyMovementSystem.hpp"

#include <cmath>
#include "core/Utils.hpp"
#include "component/TagComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/RectangleShapeComponent.hpp"

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
					f_View
						.each([&](const TagComponent& f_Tag2, RectangleShapeComponent& f_RectShape2, PositionComponent& f_Position2)
						{
							// Some variables for tweaking.
							float f_Attraction = 0.001; // Velocity toward the players.
							float f_Repulsion = -0.005; // To separate from other Smart Enemies (Must be negative).

							if (f_Tag2.Value == TagType::Player)
							{
								f_Position.Value = glm::vec2(
									LerpValue(f_Position.Value.x, f_Position2.Value.x, f_Attraction),
									LerpValue(f_Position.Value.y, f_Position2.Value.y, f_Attraction)
								);
							}

							else if (f_Tag2.Value == TagType::SmartEnemy)
							{
								if (Distance2D(f_Position.Value.x, f_Position.Value.y, f_Position2.Value.x, f_Position2
									.Value.y) < 100)
								{
									f_Position.Value = glm::vec2(
										LerpValue(f_Position.Value.x, f_Position2.Value.x, f_Repulsion),
										LerpValue(f_Position.Value.y, f_Position2.Value.y, f_Repulsion)
									);
								}
							}
						});
				}
			}
		);
}
