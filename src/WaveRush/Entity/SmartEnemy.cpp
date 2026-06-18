#include "SmartEnemy.hpp"

SmartEnemy::SmartEnemy(const glm::vec2& p_Position) :
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
			m_Position = glm::vec2(
					LerpValue(m_Position.x, f_Entity->GetPosition().x, m_Attraction),
					LerpValue(m_Position.y, f_Entity->GetPosition().y, m_Attraction));
		} else if (f_Entity->GetEntityType() == EntityType::SmartEnemy) {
			if (Distance2D(m_Position.x, m_Position.y, f_Entity->GetPosition().x, f_Entity->GetPosition().y) < 100) {
				m_Position = glm::vec2(
						LerpValue(m_Position.x, f_Entity->GetPosition().x, m_Repulsion),
						LerpValue(m_Position.y, f_Entity->GetPosition().y, m_Repulsion));
			}
		}
	}
}
