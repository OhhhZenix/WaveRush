#pragma once

#include "core/Game.hpp"
#include "Entity.hpp"

class Player : public Entity
{
private:
    sf::Vector2f m_Position;
    sf::Vector2f m_Speed;
    sf::Vector2f m_Size;
    sf::RectangleShape m_Shape;
    uint32_t m_SpeedLevel;

public:
    Player();

    void ProcessEvent(sf::Event *p_Event) override;

    void ProcessUpdate(const double p_DeltaTime) override;

    void ProcessRender(sf::RenderWindow *p_Window) override;

    const sf::Vector2f &GetPosition() const;
};