#pragma once

#include "Shape/RectangleShape.hpp"

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
	Vec2<float> m_Position;
	Vec2<float> m_Velocity;
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

	[[nodiscard]] const Vec2<float>& GetPosition() const;

	void SetPosition(const Vec2<float>& p_Position);

	[[nodiscard]] const Vec2<float>& GetVelocity() const;

	void SetVelocity(const Vec2<float>& p_Velocity);

	[[nodiscard]] const uint32_t& GetLayer() const;

	void SetLayer(const uint32_t& p_Layer);
};
