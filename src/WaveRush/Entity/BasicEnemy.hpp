#pragma once

#include "WaveRush/Core/Game.hpp"
#include "WaveRush/Core/Utils.hpp"
#include "WaveRush/Entity/Entity.hpp"

class BasicEnemy : public Entity {
private:
	float m_Speed;

public:
	explicit BasicEnemy(
			const glm::vec2& p_Position = glm::vec2(
					Random<float>(0, Game::Instance().GetSettings().Width),
					Random<float>(0, Game::Instance().GetSettings().Height)));

	void ProcessUpdate(float p_DeltaTime) override;
};