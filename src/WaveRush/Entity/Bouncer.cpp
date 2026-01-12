#include "WaveRush/Entity/Bouncer.hpp"

#include "WaveRush/Constants.hpp"

namespace WaveRush {

auto Bouncer::GetX() const -> float {
    return m_bounds.x;
}

auto Bouncer::SetX(float x) -> void {
    m_bounds.x = x;
}

auto Bouncer::GetY() const -> float {
    return m_bounds.y;
}

auto Bouncer::SetY(float y) -> void {
    m_bounds.y = y;
}

auto Bouncer::GetWidth() const -> float {
    return m_bounds.width;
}

auto Bouncer::SetWidth(float width) -> void {
    m_bounds.width = width;
}

auto Bouncer::GetHeight() const -> float {
    return m_bounds.height;
}

auto Bouncer::SetHeight(float height) -> void {
    m_bounds.height = height;
}

auto Bouncer::SetColor(Color color) -> void {
    m_color = color;
}

auto Bouncer::SetVelocityX(float velocity_x) -> void {
    m_velocity_x = velocity_x;
}

auto Bouncer::SetVelocityY(float velocity_y) -> void {
    m_velocity_y = velocity_y;
}

void Bouncer::Update(Game& game) {
    if (m_bounds.x <= 0 || m_bounds.x >= GAME_WIDTH - m_bounds.width)
        m_velocity_x *= -1.f;
    if (m_bounds.y <= 0 || m_bounds.y >= GAME_HEIGHT - m_bounds.height)
        m_velocity_y *= -1.f;

    m_bounds.x += m_velocity_x;
    m_bounds.y += m_velocity_y;
}

void Bouncer::Render() {
    DrawRectangle(
        m_bounds.x,
        m_bounds.y,
        m_bounds.width,
        m_bounds.height,
        m_color
    );
}

} // namespace WaveRush
