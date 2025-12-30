#pragma once

#include "WaveRush/Game.hpp"

namespace WaveRush {

class Scene {
  public:
    inline virtual ~Scene() {}

    virtual void Update(Game& game) = 0;
    virtual void Render(const Game& game) = 0;
};

} // namespace WaveRush
