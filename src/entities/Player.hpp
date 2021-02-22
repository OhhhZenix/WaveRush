#pragma once

#include <cstdint>
#include "Entity.hpp"

class Player : public Entity
{
private:
    uint32_t m_VelocityLevel;

public:
    Player();

    void ProcessEvent(SDL_Event *p_Event) override;

    void ProcessUpdate(const double p_DeltaTime) override;
};