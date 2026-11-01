#include "WaveRush/Entity/Player.h"

#include "raylib.h"

namespace wr {

  Player::Player(float x, float y) : x_(x), y_(y) {}

  float Player::GetX() const { return x_; }

  float Player::GetY() const { return y_; }

  void Player::Update() {
    x_ += 0.05F; // Move player to the right
    y_ += 0.05F; // Move player down
  }

  void Player::Render() { DrawRectangle(x_, y_, 32, 32, BLACK); }

} // namespace wr