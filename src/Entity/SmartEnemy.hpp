#pragma once

#include "Core/Game.hpp"
#include "Core/Utils.hpp"
#include "Entity/Entity.hpp"

class SmartEnemy : public Entity {
private:
	float m_Attraction;
	float m_Repulsion;

public:
	explicit SmartEnemy(
			const glm::vec2& p_Position = glm::vec2(
					Random<float>(0, Game::Instance().GetSettings().Width),
					Random<float>(0, Game::Instance().GetSettings().Height)));

	void ProcessUpdate(float p_DeltaTime) override;
};