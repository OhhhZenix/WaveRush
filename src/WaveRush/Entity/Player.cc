#include "WaveRush/Entity/Player.h"

namespace wr {

  Player::Player(float x, float y) : x_(x), y_(y) {}

  float Player::GetX() const { return x_; }

  float Player::GetY() const { return y_; }

} // namespace wr