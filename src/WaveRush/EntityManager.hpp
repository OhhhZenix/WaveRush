#pragma once

#include <memory>
#include <vector>

namespace WaveRush {

class Game;
class Entity;

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
