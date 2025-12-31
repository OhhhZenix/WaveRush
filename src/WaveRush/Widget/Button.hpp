#pragma once

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Button: public Widget {
  public:
    void OnClick(int button, auto action);
    void OnClickAny(int buttons[], auto action);
    void Render() override;

  private:
    float x;
    float y;
    float width;
    float height;
};

} // namespace WaveRush
