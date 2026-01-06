#pragma once

#include <raylib.h>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class Bouncer: public Entity {
  public:
    int GetX();
    void SetX(int x);

    int GetY();
    void SetY(int y);

    int GetWidth();
    void SetWidth(int width);

    int GetHeight();
    void SetHeight(int height);

    void SetColor(Color color);

    void SetVelocityX(int velocity_x);
    void SetVelocityY(int velocity_y);

    void Update(Game& game) override;
    void Render() override;

  private:
    Rectangle bounds = {
        .x = 0,
        .y = 0,
        .width = 16,
        .height = 16,
    };
    int velocity_x = 1;
    int velocity_y = 1;
    Color color = WHITE;
};

} // namespace WaveRush
