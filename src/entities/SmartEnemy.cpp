#include "SmartEnemy.hpp"

#include <iostream>
#include "core/Game.hpp"
#include "Player.hpp"
#include "Utils.hpp"

SmartEnemy::SmartEnemy() : Entity(EntityType::SmartEnemy)
{
    m_Size = sf::Vector2f(25, 25);
    m_Speed = sf::Vector2f(0.025, 0.025);
    m_Position = sf::Vector2f(random(0, Game::Instance().GetSettings()->Width - m_Size.x), random(0, Game::Instance().GetSettings()->Height - m_Size.y));
    m_Shape.setSize(m_Size);
    m_Shape.setFillColor(sf::Color(153, 197, 209));
    m_Shape.setOutlineColor(sf::Color::Black);
    m_Shape.setOutlineThickness(3);
}

void SmartEnemy::ProcessUpdate(const double p_DeltaTime)
{
    // Make enemy movement
    {
        // process for getting a player
        std::vector<Entity *> f_Players = Game::Instance().GetEntityManager().GetAllEntityWith(EntityType::Player);
        int f_PlayerIndex = random(0, f_Players.size() - 1);
        Player *f_Player = static_cast<Player *>(f_Players[f_PlayerIndex]);

        // distance between player and enemy
        float_t distance = sqrt(pow(f_Player->GetPosition().x - m_Position.x, 2) + pow(f_Player->GetPosition().y - m_Position.y, 2));

        // changing direction
        m_Position.x = lerp(m_Position.x, f_Player->GetPosition().x, m_Speed.x * distance * p_DeltaTime);
        m_Position.y = lerp(m_Position.y, f_Player->GetPosition().y, m_Speed.y * distance * p_DeltaTime);
        m_Shape.setPosition(m_Position.x, m_Position.y);
    }
}

void SmartEnemy::ProcessRender(sf::RenderWindow *p_Window)
{
    p_Window->draw(m_Shape);
}