#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

auto Label::SetText(std::string text) -> void {
    text_ = text;
}

auto Label::SetFontSize(int font_size) -> void {
    font_size_ = font_size;
}

auto Label::SetColor(Color color) -> void {
    color_ = color;
}

auto Label::GetX() const -> int {
    return x_;
}

auto Label::SetX(int x) -> void {
    x_ = x;
}

auto Label::GetY() const -> int {
    return y_;
}

auto Label::SetY(int y) -> void {
    y_ = y;
}

auto Label::Update(Game& game) -> void {}

auto Label::Render() -> void {
    if (text_.empty())
        return;

    DrawText(text_.c_str(), x_, y_, font_size_, color_);
}

} // namespace WaveRush
