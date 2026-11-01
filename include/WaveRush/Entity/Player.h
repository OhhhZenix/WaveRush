#pragma once

namespace wr {

  class Player {
  public:
    Player(float x = 0, float y = 0);
    void Update();
    void Render();
    float GetX() const;
    float GetY() const;

  private:
    float x_;
    float y_;
  };

} // namespace wr