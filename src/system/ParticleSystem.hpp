#pragma once

#include "System.hpp"

class ParticleSystem : public System
{
    public:
        void ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry) override;

        void ProcessRender(SDL_Renderer* p_Renderer, entt::registry& p_Registry) override;
}; 