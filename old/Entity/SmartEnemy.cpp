#include "SmartEnemy.hpp"

SmartEnemy::SmartEnemy(const Vec2<float>& p_Position) :
		Entity(EntityType::SmartEnemy), m_Attraction(0.001), m_Repulsion(-0.005) {
	m_Position = p_Position;
	m_Shape.Color = { 150, 0, 255, 255 };
	m_Shape.Size = { 25, 25 };
	m_Shape.OutlineColor = { 0, 0, 0, 255 };
	m_Shape.OutlineThickness = 3;
}

void SmartEnemy::ProcessUpdate(float p_DeltaTime) {
	auto f_EntityList = Game::Instance().GetSceneManager().GetActiveScene().GetEntityManager().GetEntities();

	if (f_EntityList.empty()) {
		return;
	}

	for (Entity* f_Entity : f_EntityList) {
		if (f_Entity->GetEntityType() == EntityType::Player) {
			m_Position = Vec2<float>(
					LerpValue(m_Position.X, f_Entity->GetPosition().X, m_Attraction),
					LerpValue(m_Position.Y, f_Entity->GetPosition().Y, m_Attraction));
		} else if (f_Entity->GetEntityType() == EntityType::SmartEnemy) {
			if (Distance2D(m_Position.X, m_Position.Y, f_Entity->GetPosition().X, f_Entity->GetPosition().Y) < 100) {
				m_Position = Vec2<float>(
						LerpValue(m_Position.X, f_Entity->GetPosition().X, m_Repulsion),
						LerpValue(m_Position.Y, f_Entity->GetPosition().Y, m_Repulsion));
			}
		}
	}
}
