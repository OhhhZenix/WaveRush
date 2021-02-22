#pragma once

#include "Entity.hpp"

class SmartEnemy : public Entity
{
 public:
	SmartEnemy();

	void ProcessUpdate(const double p_DeltaTime) override;
};