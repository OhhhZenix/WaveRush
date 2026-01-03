#pragma once

#include <memory>
#include <vector>

namespace WaveRush {

class Game;
class Widget;

class WidgetManager {
  public:
    void AddWidget(Widget* widget);
    void Update(Game& game);
    void Render();

  private:
    std::vector<std::unique_ptr<Widget>> widgets;
};

} // namespace WaveRush
