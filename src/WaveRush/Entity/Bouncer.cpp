#include "WaveRush/Entity/Bouncer.hpp"

#include "WaveRush/Constants.hpp"

namespace WaveRush {

float Bouncer::GetX() {
    return this->bounds.x;
}

void Bouncer::SetX(float x) {
    this->bounds.x = x;
}

float Bouncer::GetY() {
    return this->bounds.y;
}

void Bouncer::SetY(float y) {
    this->bounds.y = y;
}

float Bouncer::GetWidth() {
    return this->bounds.width;
}

void Bouncer::SetWidth(float width) {
    this->bounds.width = width;
}

float Bouncer::GetHeight() {
    return this->bounds.height;
}

void Bouncer::SetHeight(float height) {
    this->bounds.height = height;
}

void Bouncer::SetColor(Color color) {
    this->color = color;
}

void Bouncer::SetVelocityX(float velocity_x) {
    this->velocity_x = velocity_x;
}

void Bouncer::SetVelocityY(float velocity_y) {
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
