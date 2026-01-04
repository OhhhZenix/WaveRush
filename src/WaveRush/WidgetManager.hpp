#pragma once

#include <memory>
#include <vector>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class WidgetManager {
  public:
    void AddWidget(Widget* widget);
    void Update(Game& game);
    void Render();

  private:
    std::vector<std::unique_ptr<Widget>> widgets;
};

} // namespace WaveRush
