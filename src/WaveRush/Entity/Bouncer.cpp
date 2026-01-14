#include "WaveRush/Entity/Bouncer.hpp"

#include "WaveRush/Constants.hpp"

namespace WaveRush {

auto Bouncer::GetX() const -> float {
    return bounds_.x;
}

auto Bouncer::SetX(float x) -> void {
    bounds_.x = x;
}

auto Bouncer::GetY() const -> float {
    return bounds_.y;
}

auto Bouncer::SetY(float y) -> void {
    bounds_.y = y;
}

auto Bouncer::GetWidth() const -> float {
    return bounds_.width;
}

auto Bouncer::SetWidth(float width) -> void {
    bounds_.width = width;
}

auto Bouncer::GetHeight() const -> float {
    return bounds_.height;
}

auto Bouncer::SetHeight(float height) -> void {
    bounds_.height = height;
}

auto Bouncer::SetColor(Color color) -> void {
    color_ = color;
}

auto Bouncer::SetVelocityX(float velocity_x) -> void {
    velocity_x_ = velocity_x;
}

auto Bouncer::SetVelocityY(float velocity_y) -> void {
    velocity_y_ = velocity_y;
}

void Bouncer::Update(Game& game) {
    if (bounds_.x <= 0 || bounds_.x >= GAME_WIDTH - bounds_.width)
        velocity_x_ *= -1.f;
    if (bounds_.y <= 0 || bounds_.y >= GAME_HEIGHT - bounds_.height)
        velocity_y_ *= -1.f;

    bounds_.x += velocity_x_;
    bounds_.y += velocity_y_;
}

void Bouncer::Render() {
    DrawRectangle(bounds_.x, bounds_.y, bounds_.width, bounds_.height, color_);
}

} // namespace WaveRush
