#pragma once

#include "Entity/Entity.hpp"

class Player : public Entity {
private:
	int32_t m_VelocityLevel;

public:
	explicit Player(const glm::vec2& p_Position = glm::vec2());

	void ProcessEvents(SDL_Event& p_Event) override;

	void ProcessUpdate(float p_DeltaTime) override;
};