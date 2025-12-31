#pragma once

#include <functional>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Button: public Widget {
  public:
    bool IsHovered();
    void OnClick(int button, std::function<void()> action);
    void OnClickAny(int buttons[], std::function<void()> action);
    void Render() override;

  private:
    float x;
    float y;
    float width;
    float height;
};

} // namespace WaveRush
