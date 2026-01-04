#include "WaveRush/Entity/Player.hpp"

#include <raylib.h>

namespace WaveRush {

Player::Player(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

int Player::GetX() {
    return this->x;
}

void Player::SetX(int x) {
    this->x = x;
}

int Player::GetY() {
    return this->y;
}

void Player::SetY(int y) {
    this->y = y;
}

int Player::GetWidth() {
    return this->width;
}

void Player::SetWidth(int width) {
    this->width = width;
}

int Player::GetHeight() {
    return this->height;
}

void Player::SetHeight(int height) {
    this->height = height;
}

void Player::Update(Game& game) {
    if (IsKeyDown(KEY_A))
        this->x -= 1;
    if (IsKeyDown(KEY_D))
        this->x += 1;
    if (IsKeyDown(KEY_W))
        this->y -= 1;
    if (IsKeyDown(KEY_S))
        this->y += 1;
}

void Player::Render() {
    DrawRectangle(this->x, this->y, this->width, this->height, RED);
}

} // namespace WaveRush
