#include "SmartEnemy.hpp"

#include "core/Game.hpp"
#include "Utils.hpp"
#include "Player.hpp"

SmartEnemy::SmartEnemy()
{
	m_Size = {25, 25};
	m_Velocity = {0.025, 0.025};
	m_Position = {10, 10};
	m_Color = {153, 197, 209, 255};
	m_OutlineColor = {0, 0,0, 255};
	m_OutlineThickness = 3;
}

void SmartEnemy::ProcessUpdate(const double p_DeltaTime)
{
	// make enemy movement
	{
		// process for getting a player
		std::vector<Entity *> f_Players = Game::Instance().GetEntityManager().GetAllEntityWith(EntityType::Player);
		if (f_Players.empty())
			return;
		int f_PlayerIndex = random(0, f_Players.size() - 1);
		auto *f_Player = dynamic_cast<Player *>(f_Players[f_PlayerIndex]);

		// distance between player and enemy
		float_t distance = sqrt(pow(f_Player->GetPosition().X - m_Position.X, 2) + pow(f_Player->GetPosition().Y - m_Position.Y, 2));

		// changing direction
		m_Position.X = LerpValue(m_Position.X, f_Player->GetPosition().X, m_Velocity.X * distance * p_DeltaTime);
		m_Position.Y = LerpValue(m_Position.Y, f_Player->GetPosition().Y, m_Velocity.Y * distance * p_DeltaTime);
	}
}
