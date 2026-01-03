#include "WaveRush/WidgetManager.hpp"

#include "WaveRush/Widget.hpp"

namespace WaveRush {

void WidgetManager::AddWidget(Widget* widget) {
    this->widgets.emplace_back(widget);
}

void WidgetManager::Update(Game& game) {
    for (auto& widget : this->widgets)
        widget->Update(game);
}

void WidgetManager::Render() {
    for (auto& widget : this->widgets)
        widget->Render();
}

} // namespace WaveRush
