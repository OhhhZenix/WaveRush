#include "WaveRush/Entity/Player.hpp"

#include <raylib.h>

namespace WaveRush {

float Player::GetX() {
    return this->x;
}

void Player::SetX(float x) {
    this->x = x;
}

float Player::GetY() {
    return this->y;
}

void Player::SetY(float y) {
    this->y = y;
}

float Player::GetWidth() {
    return this->width;
}

void Player::SetWidth(float width) {
    this->width = width;
}

float Player::GetHeight() {
    return this->height;
}

void Player::SetHeight(float height) {
    this->height = height;
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
    DrawRectangle(this->x, this->y, this->width, this->height, RED);
}

} // namespace WaveRush
