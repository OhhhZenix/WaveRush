#pragma once

#include "system/System.hpp"

class PlayerMovementSystem : public System
{
 public:
	void ProcessUpdate(float f_Tag, entt::registry& f_Position) override;
};