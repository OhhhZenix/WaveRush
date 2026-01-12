#include "WaveRush/Entity/Player.hpp"

#include <raylib.h>

namespace WaveRush {

auto Player::GetX() const -> float {
    return m_x;
}

auto Player::SetX(float x) -> void {
    m_x = x;
}

auto Player::GetY() const -> float {
    return m_y;
}

auto Player::SetY(float y) -> void {
    m_y = y;
}

auto Player::GetWidth() const -> float {
    return m_width;
}

auto Player::SetWidth(float width) -> void {
    m_width = width;
}

auto Player::GetHeight() const -> float {
    return m_height;
}

auto Player::SetHeight(float height) -> void {
    m_height = height;
}

auto Player::SetColor(Color color) -> void {
    m_color = color;
}

void Player::Update(Game& game) {
    if (IsKeyDown(KEY_A))
        m_x -= 1.f;
    if (IsKeyDown(KEY_D))
        m_x += 1.f;
    if (IsKeyDown(KEY_W))
        m_y -= 1.f;
    if (IsKeyDown(KEY_S))
        m_y += 1.f;
}

void Player::Render() {
    DrawRectangle(m_x, m_y, m_width, m_height, m_color);
}

} // namespace WaveRush
