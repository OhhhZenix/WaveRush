#include "BasicEnemy.hpp"

#include "core/Game.hpp"
#include "Utils.hpp"

BasicEnemy::BasicEnemy() : Entity(EntityType::BasicEnemy)
{
    m_Size = sf::Vector2f(25, 25);
    m_Speed = sf::Vector2f(700, 700);
    m_Position = sf::Vector2f(random(0, Game::Instance().GetSettings()->Width - m_Size.x), random(0, Game::Instance().GetSettings()->Height - m_Size.y));
    m_Shape.setSize(m_Size);
    m_Shape.setFillColor(sf::Color::Red);
    m_Shape.setOutlineColor(sf::Color::Black);
    m_Shape.setOutlineThickness(3);
}

void BasicEnemy::ProcessUpdate(const double p_DeltaTime)
{
    // Make the enemy move
    {
        m_Position.x += m_Speed.x * p_DeltaTime;
        m_Position.y += m_Speed.y * p_DeltaTime;
    }

    // Change direction
    {
        if (m_Position.x <= 0 || m_Position.x >= Game::Instance().GetSettings()->Width - m_Size.x)
            m_Speed.x *= -1;
        if (m_Position.y <= 0 || m_Position.y >= Game::Instance().GetSettings()->Height - m_Size.y)
            m_Speed.y *= -1;
    }

    // Clamping position
    {
        m_Position.x = clamp(0, Game::Instance().GetSettings()->Width - m_Size.x, m_Position.x);
        m_Position.y = clamp(0, Game::Instance().GetSettings()->Height - m_Size.y, m_Position.y);
    }

    // Changing the position
    {
        m_Shape.setPosition(m_Position.x, m_Position.y);
    }
}

void BasicEnemy::ProcessRender(sf::RenderWindow *p_Window)
{
    p_Window->draw(m_Shape);
}