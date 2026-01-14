#include "WaveRush/Entity/Player.hpp"

#include <raylib.h>

namespace WaveRush {

auto Player::GetX() const -> float {
    return x_;
}

auto Player::SetX(float x) -> void {
    x_ = x;
}

auto Player::GetY() const -> float {
    return y_;
}

auto Player::SetY(float y) -> void {
    y_ = y;
}

auto Player::GetWidth() const -> float {
    return width_;
}

auto Player::SetWidth(float width) -> void {
    width_ = width;
}

auto Player::GetHeight() const -> float {
    return height_;
}

auto Player::SetHeight(float height) -> void {
    height_ = height;
}

auto Player::SetColor(Color color) -> void {
    color_ = color;
}

void Player::Update(Game& game) {
    if (IsKeyDown(KEY_A))
        x_ -= 1.f;
    if (IsKeyDown(KEY_D))
        x_ += 1.f;
    if (IsKeyDown(KEY_W))
        y_ -= 1.f;
    if (IsKeyDown(KEY_S))
        y_ += 1.f;
}

void Player::Render() {
    DrawRectangle(x_, y_, width_, height_, color_);
}

} // namespace WaveRush
