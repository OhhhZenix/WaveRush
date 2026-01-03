#pragma once

#include <memory>
#include <vector>

namespace WaveRush {

class Game;
class Entity;

using EntityList = std::vector<std::unique_ptr<Entity>>;

class EntityManager {
  public:
    EntityList& GetEntities();
    void AddEntity(Entity* entity);
    void Update(Game& game);
    void Render();

  private:
    EntityList entities;
};

} // namespace WaveRush
