#pragma once

#include <memory>
#include <vector>

namespace WaveRush {

class Widget {
  public:
    virtual ~Widget();
    virtual void Render() = 0;
    void AddChild(Widget* child);

  protected:
    std::vector<std::unique_ptr<Widget>> children;
};

} // namespace WaveRush
