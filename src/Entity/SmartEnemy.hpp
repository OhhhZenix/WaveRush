#pragma once

#include "Core/Game.hpp"
#include "Core/Utils.hpp"
#include "Entity/Entity.hpp"

class SmartEnemy : public Entity
{
    private:
    float m_Attraction;
    float m_Repulsion;

    public:
    explicit SmartEnemy(const Vec2f& p_Position = Vec2f(RandomF(0, Game::Instance().GetSettings().Width), RandomF(0, Game::Instance().GetSettings().Height)));

    void ProcessUpdate(float p_DeltaTime) override;
};