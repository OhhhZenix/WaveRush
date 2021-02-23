#include "BasicEnemyMovementSystem.hpp"

#include "core/Game.hpp"
#include "core/Utils.hpp"
#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"

void BasicEnemyMovementSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<const TagComponent, RectangleShapeComponent, PositionComponent, VelocityComponent>();
	f_View
		.each([p_DeltaTime](const TagComponent& f_Tag, RectangleShapeComponent& f_RectShape, PositionComponent& f_Position, VelocityComponent& f_Velocity)
		{
			// Make sure it only works on basic enemy
			if (f_Tag.Value != TagType::BasicEnemy)
				return;

			// Make the movement
			{
				f_Position.X += f_Velocity.Value.x * p_DeltaTime;
				f_Position.Y += f_Velocity.Value.y * p_DeltaTime;
			}

			// Change direction
			{
				if (f_Position.X <= 0 || f_Position.X >= Game::Instance().GetSettings().Width - f_RectShape.Size.x)
					f_Velocity.Value.x *= -1;
				if (f_Position.Y <= 0 || f_Position.Y >= Game::Instance().GetSettings().Height - f_RectShape.Size.y)
					f_Velocity.Value.y *= -1;
			}

			// Clamping position
			{
				f_Position.X = ClampValue(0, Game::Instance().GetSettings().Width - f_RectShape.Size.x, f_Position.X);
				f_Position.Y = ClampValue(0, Game::Instance().GetSettings().Height - f_RectShape.Size.y, f_Position.Y);
			}
		});
}
