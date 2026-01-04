#include "WaveRush/Widget/Button.hpp"

namespace WaveRush {

bool Button::IsHovered() {
    auto mouse_pos = GetMousePosition();
    return mouse_pos.x >= this->bounds.x
        && mouse_pos.x <= this->bounds.x + this->bounds.width
        && mouse_pos.y >= this->bounds.y
        && mouse_pos.y <= this->bounds.y + this->bounds.height;
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

void Button::SetX(int x) {
    this->bounds.x = x;
}

int Button::GetY() const {
    return this->bounds.y;
}

void Button::SetY(int y) {
    this->bounds.y = y;
}

int Button::GetWidth() const {
    return this->bounds.width;
}

void Button::SetWidth(int width) {
    this->bounds.width = width;
}

int Button::GetHeight() const {
    return this->bounds.height;
}

void Button::SetHeight(int height) {
    this->bounds.height = height;
}

void Button::SetOnClick(Callback on_click) {
    this->on_click = on_click;
}

void Button::Update(Game& game) {
    this->on_click(*this, game);
}

void Button::Render() {
    DrawRectangle(
        this->bounds.x,
        this->bounds.y,
        this->bounds.width,
        this->bounds.height,
        this->IsHovered() ? this->hover_color : this->color
    );
}

} // namespace WaveRush
