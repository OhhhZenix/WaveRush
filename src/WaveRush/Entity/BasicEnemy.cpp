#include "BasicEnemy.hpp"

BasicEnemy::BasicEnemy(const glm::vec2& p_Position) :
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
	m_Position.x += m_Velocity.x * p_DeltaTime * m_Speed;
	m_Position.y += m_Velocity.y * p_DeltaTime * m_Speed;
	m_Speed += p_DeltaTime * 0.01f;

	// Change direction
	if (m_Position.x <= 0 || m_Position.x >= Game::Instance().GetSettings().Width - m_Shape.Size.x) {
		m_Velocity.x *= -1;
	}

	if (m_Position.y <= 0 || m_Position.y >= Game::Instance().GetSettings().Height - m_Shape.Size.y) {
		m_Velocity.y *= -1;
	}

	// Clamping position
	m_Position.x = ClampValue(0, Game::Instance().GetSettings().Width - m_Shape.Size.x, m_Position.x);
	m_Position.y = ClampValue(0, Game::Instance().GetSettings().Height - m_Shape.Size.y, m_Position.y);
}
