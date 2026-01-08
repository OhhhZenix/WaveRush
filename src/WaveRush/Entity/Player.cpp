#include "WaveRush/Entity/Player.hpp"

#include <raylib.h>

namespace WaveRush {

auto Player::GetX() const -> float {
    return this->x;
}

auto Player::SetX(float x) -> void {
    this->x = x;
}

auto Player::GetY() const -> float {
    return this->y;
}

auto Player::SetY(float y) -> void {
    this->y = y;
}

auto Player::GetWidth() const -> float {
    return this->width;
}

auto Player::SetWidth(float width) -> void {
    this->width = width;
}

auto Player::GetHeight() const -> float {
    return this->height;
}

auto Player::SetHeight(float height) -> void {
    this->height = height;
}

auto Player::SetColor(Color color) -> void {
    this->color = color;
}

void Player::Update(Game& game) {
    if (IsKeyDown(KEY_A))
        this->x -= 1.f;
    if (IsKeyDown(KEY_D))
        this->x += 1.f;
    if (IsKeyDown(KEY_W))
        this->y -= 1.f;
    if (IsKeyDown(KEY_S))
        this->y += 1.f;
}

void Player::Render() {
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
}

} // namespace WaveRush
