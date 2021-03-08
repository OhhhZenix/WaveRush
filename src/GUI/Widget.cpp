#include "Widget.hpp"

Widget::Widget(const Vec2<float>& p_Position) {
	m_Position = p_Position;
}

void Widget::ProcessEvents(SDL_Event& p_Event) {}

void Widget::ProcessUpdate(float p_DeltaTime) {}

void Widget::ProcessRender(SDL_Renderer* p_Renderer) {}