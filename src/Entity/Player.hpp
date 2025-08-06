#pragma once

#include <glm/vec2.hpp>

class Player {
private:
	glm::vec2 position = { 0, 0 };

public:
	Player() = default;
	Player(const glm::vec2& position);
	glm::vec2 getPosition() const;
	void processUpdate();
	void processRender();
};