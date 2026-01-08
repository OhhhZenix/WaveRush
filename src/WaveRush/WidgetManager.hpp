#pragma once

#include <memory>
#include <vector>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class WidgetManager {
  public:
    template<typename T, typename... Args>
    auto AddWidget(Args&&... args) -> T& {
        static_assert(
            std::is_base_of_v<Widget, T>,
            "T must derive from Widget"
        );

        auto& ptr = this->widgets.emplace_back(
            std::make_unique<T>(std::forward<Args>(args)...)
        );

        return static_cast<T&>(*ptr);
    }

    auto Update(Game& game) -> void;
    auto Render() -> void;

  private:
    std::vector<std::unique_ptr<Widget>> widgets;
};

} // namespace WaveRush
