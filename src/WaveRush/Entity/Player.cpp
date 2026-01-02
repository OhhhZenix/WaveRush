#include "WaveRush/Entity/Player.hpp"
#include "raylib.h"

namespace WaveRush {

Player::Player(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Player::Update(Game& game) {}

void Player::Render() {
    DrawRectangle(this->x, this->y, this->width, this->height, RED);
}

} // namespace WaveRush
