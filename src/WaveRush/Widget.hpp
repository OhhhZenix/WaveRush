#pragma once

namespace WaveRush {

class Widget {
  public:
    virtual ~Widget();
    virtual void Render() = 0;
};

} // namespace WaveRush
