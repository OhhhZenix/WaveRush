#pragma once

#include "WaveRush/Shape/RectangleShape.hpp"
#include <SDL3/SDL.h>
#include <glm/glm.hpp>

enum class EntityType {
	Entity = 0,
	Player,
	BasicEnemy,
	SmartEnemy,
	Particle
};

class Entity {
protected:
	EntityType m_EntityType;
	RectangleShape m_Shape;
	glm::vec2 m_Position;
	glm::vec2 m_Velocity;
	uint32_t m_Layer;

public:
	explicit Entity(EntityType p_EntityType = EntityType::Entity);

	virtual ~Entity() = default;

	virtual void ProcessEvents(SDL_Event& p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);

	[[nodiscard]] EntityType GetEntityType() const;

	[[nodiscard]] const RectangleShape& GetShape() const;

	void SetShape(const RectangleShape& p_Shape);

	[[nodiscard]] const glm::vec2& GetPosition() const;

	void SetPosition(const glm::vec2& p_Position);

	[[nodiscard]] const glm::vec2& GetVelocity() const;

	void SetVelocity(const glm::vec2& p_Velocity);

	[[nodiscard]] const uint32_t& GetLayer() const;

	void SetLayer(const uint32_t& p_Layer);
};
