#pragma once

#include "WaveRush/Game.hpp"

namespace WaveRush {

class Scene {
  public:
    virtual ~Scene();
    virtual void Update(Game& game) = 0;
    virtual void Render() = 0;
};

} // namespace WaveRush
