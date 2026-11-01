#include "WaveRush/Entity/Player.h"

#include "raylib.h"

namespace wr {

  Player::Player(float x, float y) : x_(x), y_(y) {}

  float Player::GetX() const { return x_; }

  float Player::GetY() const { return y_; }

  void Player::Update() {
    float dt = GetFrameTime();
    x_ += 20 * dt;
    y_ += 20 * dt;
  }

  void Player::Render() { DrawRectangle(x_, y_, 32, 32, BLACK); }

} // namespace wr