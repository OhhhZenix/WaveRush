
#include "PlayerMovementSystem.hpp"

#include "core/Game.hpp"
#include "core/Utils.hpp"
#include "component/TagComponent.hpp"
#include "component/RectangleShapeComponent.hpp"
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"
#include "component/VelocityLevelComponent.hpp"

float VelocityByLevel(uint32_t p_Level)
{
	return 600.0f + ((float)(p_Level - 1) * 100.0f);
}

void PlayerMovementSystem::ProcessEvents(SDL_Event& p_Event, entt::registry& p_Registry)
{
	auto f_View = p_Registry.view<VelocityLevelComponent, VelocityComponent>();
	f_View.each([p_Event](VelocityLevelComponent& f_Level, VelocityComponent& f_Velocity)
	{
		if (p_Event.type == SDL_KEYUP)
		{
			switch (p_Event.key.keysym.sym)
			{
			case SDLK_LSHIFT:
			{
				f_Level.Value = ClampValue(1, 10, f_Level.Value + 1);
				float f_NewVelocity = VelocityByLevel(f_Level.Value);
				f_Velocity.Value = { f_NewVelocity, f_NewVelocity };
				break;
			}
			case SDLK_LCTRL:
			{
				f_Level.Value = ClampValue(1, 10, f_Level.Value - 1);
				float f_NewVelocity = VelocityByLevel(f_Level.Value);
				f_Velocity.Value = { f_NewVelocity, f_NewVelocity };
				break;
			}
			default:
				break;
			}
		}
	});
}

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
					f_Position.Value.y -= f_Velocity.Value.y * p_DeltaTime;
				if (f_KeyboardState[SDL_SCANCODE_S])
					f_Position.Value.y += f_Velocity.Value.y * p_DeltaTime;
				if (f_KeyboardState[SDL_SCANCODE_A])
					f_Position.Value.x -= f_Velocity.Value.x * p_DeltaTime;
				if (f_KeyboardState[SDL_SCANCODE_D])
					f_Position.Value.x += f_Velocity.Value.x * p_DeltaTime;
			}

			// Clamping the position
			{
				f_Position.Value.x = ClampValue(0, Game::Instance().GetSettings().Width - f_RectShape.Size.x, f_Position.Value.x);
				f_Position.Value.y = ClampValue(0, Game::Instance().GetSettings().Height - f_RectShape.Size.y, f_Position.Value.y);
			}
		});
}
