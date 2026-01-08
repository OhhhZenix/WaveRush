#pragma once

namespace WaveRush {

class Game;

class Widget {
  public:
    virtual ~Widget() = default;
    virtual auto Update(Game& game) -> void = 0;
    virtual auto Render() -> void = 0;
};

} // namespace WaveRush
