#include "Player.hpp"

#include "Core/Game.hpp"
#include "Core/Utils.hpp"

float VelocityByLevel(uint32_t p_Level) {
	return 600.0f + (static_cast<float>(p_Level - 1) * 100.0f);
}

Player::Player(const Vec2<float>& p_Position) :
		Entity(EntityType::Player) {
	m_VelocityLevel = 1;
	m_Position = p_Position;
	m_Velocity = { 600, 600 };
	m_Shape.Color = { 0, 255, 0, 255 };
	m_Shape.Size = { 50, 50 };
	m_Shape.OutlineColor = { 0, 0, 0, 255 };
	m_Shape.OutlineThickness = 5;
}

void Player::ProcessEvents(SDL_Event& p_Event) {
	if (p_Event.type == SDL_KEYUP) {
		switch (p_Event.key.keysym.sym) {
			case SDLK_LSHIFT: {
				m_VelocityLevel = ClampValue(1, 10, m_VelocityLevel + 1);
				float f_NewVelocity = VelocityByLevel(m_VelocityLevel);
				m_Velocity = { f_NewVelocity, f_NewVelocity };
				break;
			}
			case SDLK_LCTRL: {
				m_VelocityLevel = ClampValue(1, 10, m_VelocityLevel - 1);
				float f_NewVelocity = VelocityByLevel(m_VelocityLevel);
				m_Velocity = { f_NewVelocity, f_NewVelocity };
				break;
			}
			default:
				break;
		}
	}
}

void Player::ProcessUpdate(float p_DeltaTime) {
	// Check for player input for movement
	SDL_PumpEvents();
	const uint8_t* f_KeyboardState = SDL_GetKeyboardState(nullptr);

	if (f_KeyboardState[SDL_SCANCODE_W] || f_KeyboardState[SDL_SCANCODE_UP]) {
		m_Position.Y -= m_Velocity.Y * p_DeltaTime;
	}

	if (f_KeyboardState[SDL_SCANCODE_S] || f_KeyboardState[SDL_SCANCODE_DOWN]) {
		m_Position.Y += m_Velocity.Y * p_DeltaTime;
	}

	if (f_KeyboardState[SDL_SCANCODE_A] || f_KeyboardState[SDL_SCANCODE_LEFT]) {
		m_Position.X -= m_Velocity.X * p_DeltaTime;
	}

	if (f_KeyboardState[SDL_SCANCODE_D] || f_KeyboardState[SDL_SCANCODE_RIGHT]) {
		m_Position.X += m_Velocity.X * p_DeltaTime;
	}

	// Clamping the position
	m_Position.X = ClampValue(0, Game::Instance().GetSettings().Width - m_Shape.Size.X, m_Position.X);
	m_Position.Y = ClampValue(0, Game::Instance().GetSettings().Height - m_Shape.Size.Y, m_Position.Y);
}
