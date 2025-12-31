#include "WaveRush/Widget/Button.hpp"

namespace WaveRush {

// Button::~Button() {}

bool Button::IsHovered() {
    return false;
}

void Button::OnClick(int button, std::function<void()> action) {
    if (!IsHovered())
        return;
    action();
}

void Button::OnClickAny(int buttons[], std::function<void()> action) {
    if (!IsHovered())
        return;
    action();
}

void Button::Render() {}

} // namespace WaveRush
