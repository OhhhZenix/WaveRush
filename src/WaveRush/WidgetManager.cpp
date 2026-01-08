#include "WaveRush/WidgetManager.hpp"

#include "WaveRush/Widget.hpp"

namespace WaveRush {

auto WidgetManager::Update(Game& game) -> void {
    for (auto& widget : this->widgets)
        widget->Update(game);
}

auto WidgetManager::Render() -> void {
    for (auto& widget : this->widgets)
        widget->Render();
}

} // namespace WaveRush
