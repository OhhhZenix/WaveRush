#pragma once

#include <raylib.h>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class Bouncer: public Entity {
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

    auto SetVelocityX(float velocity_x) -> void;
    auto SetVelocityY(float velocity_y) -> void;

    void Update(Game& game) override;
    void Render() override;

  private:
    Rectangle m_bounds = {
        .x = 0,
        .y = 0,
        .width = 16,
        .height = 16,
    };
    float m_velocity_x = 1.f;
    float m_velocity_y = 1.f;
    Color m_color = WHITE;
};

} // namespace WaveRush
