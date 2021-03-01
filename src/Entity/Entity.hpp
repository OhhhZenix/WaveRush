#pragma once

#include "Shape/RectangleShape.hpp"

enum class EntityType
{
	Entity = 0,
	Player,
	BasicEnemy,
	SmartEnemy,
	Particle
};

class Entity
{
 protected:
	EntityType m_EntityType;
	RectangleShape m_Shape;
	Vec2f m_Position;
	Vec2f m_Velocity;

 public:
	explicit Entity(EntityType p_EntityType = EntityType::Entity);

	virtual ~Entity() = default;

	virtual void ProcessEvents(SDL_Event& p_Event);

	virtual void ProcessUpdate(float p_DeltaTime);

	virtual void ProcessRender(SDL_Renderer* p_Renderer);

	[[nodiscard]] EntityType GetEntityType() const;

	[[nodiscard]] const RectangleShape& GetShape() const;

	void SetShape(const RectangleShape& p_Shape);

	[[nodiscard]] const Vec2f& GetPosition() const;

	void SetPosition(const Vec2f& p_Position);

	[[nodiscard]] const Vec2f& GetVelocity() const;

	void SetVelocity(const Vec2f& p_Velocity);
};
