#pragma once

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class Player: public Entity {
  public:
    Player(int x = 0, int y = 0, int width = 24, int height = 24);

    int GetX();
    void SetX(int x);

    int GetY();
    void SetY(int y);

    int GetWidth();
    void SetWidth(int width);

    int GetHeight();
    void SetHeight(int height);

    void Update(Game& game) override;
    void Render() override;

  private:
    int x;
    int y;
    int width;
    int height;
};

} // namespace WaveRush
