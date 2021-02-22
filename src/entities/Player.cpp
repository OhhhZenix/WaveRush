#include "Player.hpp"

#include "core/Game.hpp"
#include "Utils.hpp"

double speedByLevel(uint32_t level)
{
    return 600 + ((level - 1) * 100);
}

Player::Player() : Entity(EntityType::Player)
{
    m_SpeedLevel = 1;
    m_Size = sf::Vector2f(50, 50);
    m_Speed = sf::Vector2f(600, 600);
    m_Position = sf::Vector2f(Game::Instance().GetSettings()->Width / 2, Game::Instance().GetSettings()->Height / 2);
    m_Shape.setSize(m_Size);
    m_Shape.setFillColor(sf::Color::Green);
    m_Shape.setOutlineColor(sf::Color::Black);
    m_Shape.setOutlineThickness(5);
}

void Player::ProcessEvent(sf::Event *p_Event)
{
    if (p_Event->type == sf::Event::KeyReleased)
    {
        if (p_Event->key.code == sf::Keyboard::LShift)
            m_SpeedLevel = clamp(1, 10, m_SpeedLevel + 1);
        if (p_Event->key.code == sf::Keyboard::LControl)
            m_SpeedLevel = clamp(1, 10, m_SpeedLevel - 1);
    }
}

void Player::ProcessUpdate(const double p_DeltaTime)
{
    // Check for speed adjustment
    {
        double f_NewSpeed = speedByLevel(m_SpeedLevel);
        m_Speed = sf::Vector2f(f_NewSpeed, f_NewSpeed);
        std::cout << "speed level " << m_SpeedLevel << " speed " << m_Speed.x << "," << m_Speed.y << "\n";
    }

    // Check for player input for movement
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            m_Position.y -= m_Speed.y * p_DeltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            m_Position.y += m_Speed.y * p_DeltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            m_Position.x -= m_Speed.x * p_DeltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            m_Position.x += m_Speed.x * p_DeltaTime;
    }

    // Clamping player position
    {
        m_Position.x = clamp(0, Game::Instance().GetSettings()->Width - m_Size.x, m_Position.x);
        m_Position.y = clamp(0, Game::Instance().GetSettings()->Height - m_Size.y, m_Position.y);
    }

    // Changing player position
    {
        m_Shape.setPosition(m_Position.x, m_Position.y);
    }
}

void Player::ProcessRender(sf::RenderWindow *p_Window)
{
    p_Window->draw(m_Shape);
}

const sf::Vector2f &Player::GetPosition() const
{
    return m_Position;
}