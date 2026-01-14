#pragma once

namespace WaveRush {

class Window {
  public:
    Window();
    ~Window();

    auto ShouldClose() const -> bool;
    auto Close() -> void;

  private:
    bool should_close_ = false;
};

} // namespace WaveRush
