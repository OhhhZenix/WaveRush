#pragma once

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class Player: public Entity {
  public:
    Player(int x = 0, int y = 0, int width = 24, int height = 24);
    void Update(Game& game) override;
    void Render() override;

  private:
    int x;
    int y;
    int width;
    int height;
};

} // namespace WaveRush
