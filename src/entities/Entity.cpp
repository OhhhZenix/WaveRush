#include "Entity.hpp"

const EntityType& Entity::GetEntityType() const
{
	return m_EntityType;
}

const Vector2f& Entity::GetPosition() const
{
	return m_Position;
}

const Vector2f& Entity::GetVelocity() const
{
	return m_Velocity;
}

const Vector2f& Entity::GetSize() const
{
	return m_Size;
}

bool Entity::IsVisible() const
{
	return m_Visibility;
}

void Entity::ProcessEvent(SDL_Event* p_Event)
{
}

void Entity::ProcessUpdate(float p_DeltaTime)
{
}

void Entity::ProcessRender(SDL_Renderer* p_Renderer)
{
	if (m_Visibility)
	{
		SDL_Rect f_Rect{ (int)m_Position.X, (int)m_Position.Y, (int)m_Size.X, (int)m_Size.Y };

		if (m_OutlineThickness > 0)
		{
			SDL_Rect f_Outline{ f_Rect.x - m_OutlineThickness, f_Rect.y - m_OutlineThickness,
								f_Rect.w + (m_OutlineThickness * 2), f_Rect.h + (m_OutlineThickness * 2) };
			SDL_SetRenderDrawColor(p_Renderer, m_OutlineColor.r, m_OutlineColor.g, m_OutlineColor.b, m_OutlineColor.a);
			SDL_RenderFillRect(p_Renderer, &f_Outline);
		}

		SDL_SetRenderDrawColor(p_Renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);
		SDL_RenderFillRect(p_Renderer, &f_Rect);
	}
}