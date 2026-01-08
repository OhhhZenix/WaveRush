#include "WaveRush/Widget/Button.hpp"

namespace WaveRush {

auto Button::IsHovered() const -> bool {
    auto mouse_pos = GetMousePosition();
    return mouse_pos.x >= this->bounds.x
        && mouse_pos.x <= this->bounds.x + this->bounds.width
        && mouse_pos.y >= this->bounds.y
        && mouse_pos.y <= this->bounds.y + this->bounds.height;
}

auto Button::IsLeftClicked() const -> bool {
    if (!this->IsHovered())
        return false;
    if (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        return false;
    return true;
}

auto Button::IsRightClicked() const -> bool {
    if (!this->IsHovered())
        return false;
    if (!IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        return false;
    return true;
}

auto Button::GetX() const -> int {
    return this->bounds.x;
}

auto Button::SetX(int x) -> void {
    this->bounds.x = x;
}

auto Button::GetY() const -> int {
    return this->bounds.y;
}

auto Button::SetY(int y) -> void {
    this->bounds.y = y;
}

auto Button::GetWidth() const -> int {
    return this->bounds.width;
}

auto Button::SetWidth(int width) -> void {
    this->bounds.width = width;
}

auto Button::GetHeight() const -> int {
    return this->bounds.height;
}

auto Button::SetHeight(int height) -> void {
    this->bounds.height = height;
}

auto Button::SetOnClick(Callback on_click) -> void {
    this->on_click = on_click;
}

auto Button::SetText(std::string text) -> void {
    this->text = text;
}

auto Button::SetFontSize(int font_size) -> void {
    this->font_size = font_size;
}

auto Button::Update(Game& game) -> void {
    this->on_click(*this, game);
}

auto Button::Render() -> void {
    DrawRectangle(
        this->bounds.x,
        this->bounds.y,
        this->bounds.width,
        this->bounds.height,
        this->IsHovered() ? this->hover_color : this->color
    );

    if (!text.empty()) {
        int text_width = MeasureText(text.c_str(), this->font_size);
        DrawText(
            text.c_str(),
            bounds.x + bounds.width / 2 - static_cast<float>(text_width) / 2,
            bounds.y + bounds.height / 2
                - static_cast<float>(this->font_size) / 2,
            this->font_size,
            BLACK
        );
    }
}

} // namespace WaveRush
