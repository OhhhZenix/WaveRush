#pragma once

namespace WaveRush {

class Window {
  public:
    Window();
    ~Window();

    auto ShouldClose() const -> bool;
    auto Close() -> void;

  private:
    bool m_should_close = false;
};

} // namespace WaveRush
