#pragma once

#include <memory>
#include <vector>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class WidgetManager {
  public:
    auto AddWidget(Widget* widget) -> void;
    auto Update(Game& game) -> void;
    auto Render() -> void;

  private:
    std::vector<std::unique_ptr<Widget>> widgets;
};

} // namespace WaveRush
