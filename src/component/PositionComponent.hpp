#pragma once

#include <glm/glm.hpp>

struct PositionComponent
{
	~PositionComponent()
	{
		printf("Position Destroyed\n");
	};

	glm::vec2 Value = glm::vec2(0, 0);
};