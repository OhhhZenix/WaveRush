#pragma once

#include "Entity/Entity.hpp"

class Particle : public Entity
{
 public:
	explicit Particle(const Vec2f& p_Position = Vec2f());

	void ProcessUpdate(float p_DeltaTime) override;
};