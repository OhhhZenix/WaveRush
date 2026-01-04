#pragma once

#include <memory>
#include <vector>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

class EntityManager {
  public:
    using EntityList = std::vector<std::unique_ptr<Entity>>;

    EntityList& GetEntities();
    void AddEntity(Entity* entity);
    void Update(Game& game);
    void Render();

  private:
    EntityList entities;
};

} // namespace WaveRush
