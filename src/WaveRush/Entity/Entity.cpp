#include "Entity.hpp"

Entity::Entity(EntityType p_EntityType) {
	m_EntityType = p_EntityType;
	m_Layer = 0;
}

void Entity::ProcessEvents(SDL_Event& p_Event) {}

void Entity::ProcessUpdate(float p_DeltaTime) {}

void Entity::ProcessRender(SDL_Renderer* p_Renderer) {
	SDL_Rect f_Rect{ (int)m_Position.x, (int)m_Position.y, (int)m_Shape.Size.x, (int)m_Shape.Size.x };

	if (m_Shape.OutlineThickness > 0) {
		SDL_Rect f_Outline{ static_cast<int>(f_Rect.x - m_Shape.OutlineThickness),
			static_cast<int>(f_Rect.y - m_Shape.OutlineThickness),
			static_cast<int>(f_Rect.w + (m_Shape.OutlineThickness * 2)),
			static_cast<int>(f_Rect.h + (m_Shape.OutlineThickness * 2)) };
		SDL_SetRenderDrawColor(p_Renderer, m_Shape.OutlineColor.r, m_Shape.OutlineColor.g, m_Shape.OutlineColor.b, m_Shape.OutlineColor.a);
		SDL_RenderFillRect(p_Renderer, &f_Outline);
	}

	SDL_SetRenderDrawColor(p_Renderer, m_Shape.Color.r, m_Shape.Color.g, m_Shape.Color.b, m_Shape.Color.a);
	SDL_RenderFillRect(p_Renderer, &f_Rect);
}

EntityType Entity::GetEntityType() const {
	return m_EntityType;
}

const RectangleShape& Entity::GetShape() const {
	return m_Shape;
}

void Entity::SetShape(const RectangleShape& p_Shape) {
	m_Shape = p_Shape;
}

const glm::vec2& Entity::GetPosition() const {
	return m_Position;
}

void Entity::SetPosition(const glm::vec2& p_Position) {
	m_Position = p_Position;
}

const glm::vec2& Entity::GetVelocity() const {
	return m_Velocity;
}

void Entity::SetVelocity(const glm::vec2& p_Velocity) {
	m_Velocity = p_Velocity;
}

const uint32_t& Entity::GetLayer() const {
	return m_Layer;
}

void Entity::SetLayer(const uint32_t& p_Layer) {
	m_Layer = p_Layer;
}