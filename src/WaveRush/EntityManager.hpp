#pragma once

#include <memory>
#include <vector>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class EntityManager {
  public:
    using EntityList = std::vector<std::unique_ptr<Entity>>;

    auto GetEntities() -> EntityList&;
    auto AddEntity(Entity* entity) -> void;
    auto Update(Game& game) -> void;
    auto Render() -> void;

  private:
    EntityList entities;
};

} // namespace WaveRush
