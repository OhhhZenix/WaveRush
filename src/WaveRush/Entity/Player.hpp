#pragma once

#include "WaveRush/Entity.hpp"
#include "raylib.h"

namespace WaveRush {

class Player: public Entity {
  public:
    auto GetX() const -> float;
    auto SetX(float x) -> void;

    auto GetY() const -> float;
    auto SetY(float y) -> void;

    auto GetWidth() const -> float;
    auto SetWidth(float width) -> void;

    auto GetHeight() const -> float;
    auto SetHeight(float height) -> void;

    auto SetColor(Color color) -> void;

    void Update(Game& game) override;
    void Render() override;

  private:
    float m_x = 0.f;
    float m_y = 0.f;
    float m_width = 24.f;
    float m_height = 24.f;
    Color m_color = WHITE;
};

} // namespace WaveRush
