#pragma once

#include "system/System.hpp"

class SmartEnemyMovementSystem : public System
{
 public:
	void ProcessUpdate(float p_DeltaTime, entt::registry &p_Registry) override;
};