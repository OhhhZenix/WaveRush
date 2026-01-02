#pragma once

namespace WaveRush {

class Game;

class Entity {
  public:
    virtual ~Entity();
    virtual void Update(Game& game) = 0;
    virtual void Render() = 0;
};

} // namespace WaveRush
