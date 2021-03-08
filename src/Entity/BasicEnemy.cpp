#include "BasicEnemy.hpp"

BasicEnemy::BasicEnemy(const Vec2<float>& p_Position) :
		Entity(EntityType::BasicEnemy) {
	m_Speed = 0.3f;
	m_Position = p_Position;
	m_Velocity = { 700, 700 };
	m_Shape.Color = { 155, 0, 0, 255 };
	m_Shape.Size = { 25, 25 };
	m_Shape.OutlineColor = { 0, 0, 0, 255 };
	m_Shape.OutlineThickness = 3;
}

void BasicEnemy::ProcessUpdate(float p_DeltaTime) {
	// Make the movement
	m_Position.X += m_Velocity.X * p_DeltaTime * m_Speed;
	m_Position.Y += m_Velocity.Y * p_DeltaTime * m_Speed;
	m_Speed += p_DeltaTime * 0.01f;

	// Change direction
	if (m_Position.X <= 0 || m_Position.X >= Game::Instance().GetSettings().Width - m_Shape.Size.X) {
		m_Velocity.X *= -1;
	}

	if (m_Position.Y <= 0 || m_Position.Y >= Game::Instance().GetSettings().Height - m_Shape.Size.Y) {
		m_Velocity.Y *= -1;
	}

	// Clamping position
	m_Position.X = ClampValue(0, Game::Instance().GetSettings().Width - m_Shape.Size.X, m_Position.X);
	m_Position.Y = ClampValue(0, Game::Instance().GetSettings().Height - m_Shape.Size.Y, m_Position.Y);
}
