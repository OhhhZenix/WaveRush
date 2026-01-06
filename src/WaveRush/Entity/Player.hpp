#pragma once

#include "WaveRush/Entity.hpp"

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

    void Update(Game& game) override;
    void Render() override;

  private:
    float x = 0.f;
    float y = 0.f;
    float width = 24.f;
    float height = 24.f;
};

} // namespace WaveRush
