#pragma once

#include "Entity.hpp"

class BasicEnemy : public Entity
{
public:
    BasicEnemy();

    void ProcessUpdate(const double p_DeltaTime) override;
};