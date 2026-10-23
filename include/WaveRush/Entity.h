#pragma once

#include "WaveRush/Game.h"

namespace wr {

  class Entity {
  public:
    virtual ~Entity();
    bool IsAlive() const;
    void SetAlive(bool value);
    virtual void OnUpdate(wr::Game& game) = 0;
    virtual void OnRender(const wr::Game& game) = 0;

  private:
    bool alive_;
  };

  class Player : public Entity {
  public:
    Player(float x, float y);

  private:
    float x_;
    float y_;
  };

} // namespace wr