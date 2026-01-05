#include "WaveRush/Widget/Label.hpp"

namespace WaveRush {

void Label::SetText(std::string text) {
    this->text = text;
}

void Label::SetFontSize(int font_size) {
    this->font_size = font_size;
}

void Label::SetColor(Color color) {
    this->color = color;
}

int Label::GetX() {
    return this->x;
}

void Label::SetX(int x) {
    this->x = x;
}

int Label::GetY() {
    return this->y;
}

void Label::SetY(int y) {
    this->y = y;
}

void Label::Update(Game& game) {}

void Label::Render() {
    if (this->text.empty())
        return;

    DrawText(text.c_str(), this->x, this->y, this->font_size, this->color);
}

} // namespace WaveRush
