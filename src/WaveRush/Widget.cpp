#include "WaveRush/Widget.hpp"

namespace WaveRush {

Widget::~Widget() {}

void Widget::AddChild(Widget* child) {
    this->children.emplace_back(std::move(child));
}

} // namespace WaveRush
