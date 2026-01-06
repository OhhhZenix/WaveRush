#pragma once

#include "WaveRush/Entity.hpp"
#include "raylib.h"

namespace WaveRush {

class Player: public Entity {
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

    void Update(Game& game) override;
    void Render() override;

  private:
    float x = 0.f;
    float y = 0.f;
    float width = 24.f;
    float height = 24.f;
    Color color = WHITE;
};

} // namespace WaveRush
