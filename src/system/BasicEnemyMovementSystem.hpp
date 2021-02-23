#pragma once

#include "system/System.hpp"

class BasicEnemyMovementSystem : public System
{
 public:
	void ProcessUpdate(float p_DeltaTime, entt::registry &p_Registry) override;
};
