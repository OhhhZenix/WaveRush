#include "WaveRush/Widget/Button.hpp"

namespace WaveRush {

Button::Button(
    int x,
    int y,
    int width,
    int height,
    Color color,
    Color hoverColor
) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
    this->hoverColor = hoverColor;
}

// Button::~Button() {}

bool Button::IsHovered() {
    auto mouse_pos = GetMousePosition();
    return mouse_pos.x >= this->x && mouse_pos.x <= this->x + this->width
        && mouse_pos.y >= this->y && mouse_pos.y <= this->y + this->height;
}

bool Button::IsLeftClicked() {
    if (!this->IsHovered())
        return false;
    if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        return false;
    return true;
}

bool Button::IsRightClicked() {
    if (!this->IsHovered())
        return false;
    if (!IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        return false;
    return true;
}

int Button::GetX() const {
    return this->x;
}

int Button::GetY() const {
    return this->y;
}

int Button::GetWidth() const {
    return this->width;
}

int Button::GetHeight() const {
    return this->height;
}

void Button::SetX(int x) {
    this->x = x;
}

void Button::SetY(int y) {
    this->y = y;
}

void Button::SetWidth(int width) {
    this->width = width;
}

void Button::SetHeight(int height) {
    this->height = height;
}

void Button::Render() {
    DrawRectangle(
        this->x,
        this->y,
        this->width,
        this->height,
        this->IsHovered() ? this->hoverColor : this->color
    );
}

} // namespace WaveRush
