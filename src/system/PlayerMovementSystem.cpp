
#include "PlayerMovementSystem.hpp"

#include "core/Game.hpp"
#include "core/Utils.hpp"
#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"

void PlayerMovementSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<const TagComponent, RectangleShapeComponent, PositionComponent, VelocityComponent>();
	f_View
		.each([p_DeltaTime](const TagComponent& f_Tag, RectangleShapeComponent& f_RectShape, PositionComponent& f_Position, VelocityComponent& f_Velocity)
		{
			// Checks to make sure it is some sort of player entity
			if (f_Tag.Value != TagType::Player)
				return;

			// Check for player input for movement
			{
				SDL_PumpEvents();
				const uint8_t* f_KeyboardState = SDL_GetKeyboardState(nullptr);
				if (f_KeyboardState[SDL_SCANCODE_W])
					f_Position.Y -= f_Velocity.Value.y * p_DeltaTime;
				if (f_KeyboardState[SDL_SCANCODE_S])
					f_Position.Y += f_Velocity.Value.y * p_DeltaTime;
				if (f_KeyboardState[SDL_SCANCODE_A])
					f_Position.X -= f_Velocity.Value.x * p_DeltaTime;
				if (f_KeyboardState[SDL_SCANCODE_D])
					f_Position.X += f_Velocity.Value.x * p_DeltaTime;
			}

			// Clamping the position
			{
				f_Position.X = ClampValue(0, Game::Instance().GetSettings().Width - f_RectShape.Size.x, f_Position.X);
				f_Position.Y = ClampValue(0, Game::Instance().GetSettings().Height - f_RectShape.Size.y, f_Position.Y);
			}
		});
}