#pragma once

namespace WaveRush {

class Game;

class Entity {
  public:
    virtual ~Entity() = default;
    virtual auto Update(Game& game) -> void = 0;
    virtual auto Render() -> void = 0;
};

} // namespace WaveRush
