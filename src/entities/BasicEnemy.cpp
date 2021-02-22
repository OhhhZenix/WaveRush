#include "BasicEnemy.hpp"

#include "core/Game.hpp"
#include "math/Math.hpp"
#include "Utils.hpp"

BasicEnemy::BasicEnemy()
{
    m_Size = {25, 25};
    m_Velocity = {700, 700};
    m_Position = {random(0, Game::Instance().GetSettings()->Width - m_Size.X), random(0, Game::Instance().GetSettings()->Height - m_Size.Y)};
    m_Color = {255, 0, 0, 255};
    m_OutlineColor = {0, 0, 0, 255};
    m_OutlineThickness = 3;
}

void BasicEnemy::ProcessUpdate(const double p_DeltaTime)
{
    // Make the movement
    {
        m_Position.X += m_Velocity.X * p_DeltaTime;
        m_Position.Y += m_Velocity.Y * p_DeltaTime;
    }

    // Change direction
    {
        if (m_Position.X <= 0 || m_Position.X >= Game::Instance().GetSettings()->Width - m_Size.X)
            m_Velocity.X *= -1;
        if (m_Position.Y <= 0 || m_Position.Y >= Game::Instance().GetSettings()->Height - m_Size.Y)
            m_Velocity.Y *= -1;
    }

    // Clamping position
    {
        m_Position.X = ClampValue(0, Game::Instance().GetSettings()->Width - m_Size.X, m_Position.X);
        m_Position.Y = ClampValue(0, Game::Instance().GetSettings()->Height - m_Size.Y, m_Position.Y);
    }
}