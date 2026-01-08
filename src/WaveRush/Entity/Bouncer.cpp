#include "WaveRush/Entity/Bouncer.hpp"

#include "WaveRush/Constants.hpp"

namespace WaveRush {

auto Bouncer::GetX() const -> float {
    return this->bounds.x;
}

auto Bouncer::SetX(float x) -> void {
    this->bounds.x = x;
}

auto Bouncer::GetY() const -> float {
    return this->bounds.y;
}

auto Bouncer::SetY(float y) -> void {
    this->bounds.y = y;
}

auto Bouncer::GetWidth() const -> float {
    return this->bounds.width;
}

auto Bouncer::SetWidth(float width) -> void {
    this->bounds.width = width;
}

auto Bouncer::GetHeight() const -> float {
    return this->bounds.height;
}

auto Bouncer::SetHeight(float height) -> void {
    this->bounds.height = height;
}

auto Bouncer::SetColor(Color color) -> void {
    this->color = color;
}

auto Bouncer::SetVelocityX(float velocity_x) -> void {
    this->velocity_x = velocity_x;
}

auto Bouncer::SetVelocityY(float velocity_y) -> void {
    this->velocity_y = velocity_y;
}

void Bouncer::Update(Game& game) {
    if (this->bounds.x <= 0
        || this->bounds.x >= GAME_WIDTH - this->bounds.width)
        this->velocity_x *= -1.f;
    if (this->bounds.y <= 0
        || this->bounds.y >= GAME_HEIGHT - this->bounds.height)
        this->velocity_y *= -1.f;

    this->bounds.x += this->velocity_x;
    this->bounds.y += this->velocity_y;
}

void Bouncer::Render() {
    DrawRectangle(
        this->bounds.x,
        this->bounds.y,
        this->bounds.width,
        this->bounds.height,
        this->color
    );
}

} // namespace WaveRush
