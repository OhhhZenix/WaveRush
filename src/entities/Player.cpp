#include "Player.hpp"

#include "core/Game.hpp"
#include "math/Math.hpp"
#include "Utils.hpp"

float VelocityByLevel(uint32_t p_Level)
{
	return 600 + ((p_Level - 1) * 100);
}

Player::Player()
{
	m_VelocityLevel = 1;
	m_Color = { 0, 255, 0, 255 };
	m_Size = { 50, 50 };
	m_Velocity = { 600, 600 };
	m_Position = { (Game::Instance().GetSettings()->Width / 2) - m_Size.X,
				   (Game::Instance().GetSettings()->Height / 2) - m_Size.Y };
	m_OutlineColor = { 0, 0, 0, 255 };
	m_OutlineThickness = 5;
	m_Visibility = true;
}

void Player::ProcessEvent(SDL_Event* p_Event)
{
	if (p_Event->type == SDL_KEYDOWN)
	{
		if (p_Event->key.keysym.sym == SDLK_LSHIFT)
			m_VelocityLevel = ClampValue(1, 10, m_VelocityLevel + 1);
		if (p_Event->key.keysym.sym == SDLK_LCTRL)
			m_VelocityLevel = ClampValue(1, 10, m_VelocityLevel - 1);
	}
}

void Player::ProcessUpdate(float p_DeltaTime)
{
	// Check for velocity adjustment
	{
		float f_NewVelocity = VelocityByLevel(m_VelocityLevel);
		m_Velocity = { f_NewVelocity, f_NewVelocity };
	}

	// Check for player input for movement
	{
		const uint8_t* f_KeyboardState = SDL_GetKeyboardState(NULL);
		if (f_KeyboardState[SDL_SCANCODE_W])
			m_Position.Y -= m_Velocity.Y * p_DeltaTime;
		if (f_KeyboardState[SDL_SCANCODE_S])
			m_Position.Y += m_Velocity.Y * p_DeltaTime;
		if (f_KeyboardState[SDL_SCANCODE_A])
			m_Position.X -= m_Velocity.X * p_DeltaTime;
		if (f_KeyboardState[SDL_SCANCODE_D])
			m_Position.X += m_Velocity.X * p_DeltaTime;
	}

	// Clamping the position
	{
		m_Position.X = ClampValue(0, Game::Instance().GetSettings()->Width - m_Size.X, m_Position.X);
		m_Position.Y = ClampValue(0, Game::Instance().GetSettings()->Height - m_Size.Y, m_Position.Y);
	}
}