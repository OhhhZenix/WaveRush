#pragma  once

#include <glm/glm.hpp>

struct RectangleShapeComponent
{
	glm::vec4 Color = glm::vec4();
	glm::vec2 Size = glm::vec2();
	glm::vec4 OutlineColor = glm::vec4();
	uint32_t OutlineThickness = 0;
};