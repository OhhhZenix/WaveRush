#pragma once

#include <raylib.h>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class Bouncer: public Entity {
  public:
    float GetX();
    void SetX(float x);

    float GetY();
    void SetY(float y);

    float GetWidth();
    void SetWidth(float width);

    float GetHeight();
    void SetHeight(float height);

    void SetColor(Color color);

    void SetVelocityX(float velocity_x);
    void SetVelocityY(float velocity_y);

    void Update(Game& game) override;
    void Render() override;

  private:
    Rectangle bounds = {
        .x = 0,
        .y = 0,
        .width = 16,
        .height = 16,
    };
    float velocity_x = 1.f;
    float velocity_y = 1.f;
    Color color = WHITE;
};

} // namespace WaveRush
