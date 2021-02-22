#pragma once

#include "Entity.hpp"

class BasicEnemy : public Entity
{
 public:
	BasicEnemy();

	void ProcessUpdate(float p_DeltaTime) override;
};