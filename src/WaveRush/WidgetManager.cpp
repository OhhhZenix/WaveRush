#include "WaveRush/WidgetManager.hpp"

#include "WaveRush/Widget.hpp"

namespace WaveRush {

auto WidgetManager::Update(Game& game) -> void {
    for (auto& widget : this->m_widgets)
        widget->Update(game);
}

auto WidgetManager::Render() -> void {
    for (auto& widget : this->m_widgets)
        widget->Render();
}

} // namespace WaveRush
