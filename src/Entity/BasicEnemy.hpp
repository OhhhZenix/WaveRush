#pragma once

#include "Core/Game.hpp"
#include "Core/Utils.hpp"
#include "Entity/Entity.hpp"

class BasicEnemy : public Entity {
private:
	float m_Speed;

public:
	explicit BasicEnemy(
			const Vec2<float>& p_Position = Vec2<float>(
					Random<float>(0, Game::Instance().GetSettings().Width),
					Random<float>(0, Game::Instance().GetSettings().Height)));

	void ProcessUpdate(float p_DeltaTime) override;
};