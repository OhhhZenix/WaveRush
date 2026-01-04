#include "WaveRush/Widget/Button.hpp"

namespace WaveRush {

Button::Button(
    int x,
    int y,
    int width,
    int height,
    Color color,
    Color hover_color,
    ButtonCallback on_click
) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->color = color;
    this->hover_color = hover_color;
    this->on_click = on_click;
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
    return this->bounds.x;
}

int Button::GetY() const {
    return this->bounds.y;
}

int Button::GetWidth() const {
    return this->bounds.width;
}

int Button::GetHeight() const {
    return this->bounds.height;
}

void Button::SetX(int x) {
    this->bounds.x = x;
}

void Button::SetY(int y) {
    this->bounds.y = y;
}

void Button::SetWidth(int width) {
    this->bounds.width = width;
}

void Button::SetHeight(int height) {
    this->bounds.height = height;
}

void Button::Update(Game& game) {
    this->on_click(game);
}

void Button::Render() {
    DrawRectangle(
        this->x,
        this->y,
        this->width,
        this->height,
        this->IsHovered() ? this->hover_color : this->color
    );
}

} // namespace WaveRush
