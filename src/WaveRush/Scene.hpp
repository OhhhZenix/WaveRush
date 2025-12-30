#pragma once

namespace WaveRush {

class Scene {
  public:
    virtual void Update() = 0;
    virtual void Render() = 0;
};

} // namespace WaveRush
