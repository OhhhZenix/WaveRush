#pragma once

#include "WaveRush/Core/PCH.hpp"

class Widget {
protected:
	glm::vec2 m_Position;

public:
	explicit Widget(const glm::vec2& p_Position = glm::vec2(0, 0));

	virtual ~Widget() = default;

	virtual void ProcessEvents(SDL_Event& p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);
};