#pragma once

#include "Core/PCH.hpp"
#include "Math/Vec2.hpp"

class Widget {
protected:
	Vec2<float> m_Position;

public:
	explicit Widget(const Vec2<float>& p_Position = Vec2<float>());

	virtual ~Widget() = default;

	virtual void ProcessEvents(SDL_Event& p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);
};