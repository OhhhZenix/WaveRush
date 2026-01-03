#pragma once

namespace WaveRush {

class Game;

class Widget {
  public:
    virtual ~Widget() = default;
    virtual void Update(Game& game) = 0;
    virtual void Render() = 0;
};

} // namespace WaveRush
