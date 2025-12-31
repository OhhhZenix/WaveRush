#include "WaveRush/Widget/Button.hpp"

#include "raylib.h"

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

void Button::OnClick(int button, std::function<void()> action) {
    if (!this->IsHovered())
        return;
    action();
}

void Button::OnClickAny(int buttons[], std::function<void()> action) {
    if (!this->IsHovered())
        return;
    action();
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
