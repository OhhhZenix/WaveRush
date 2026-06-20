#include "World.hpp"

namespace wr {

auto World::addEntity() -> Entity& {
  while (entities_.at(next_slot_).dead == false) {
    next_slot_ = (next_slot_ + 1) % entities_.size();
  }
  auto& e = entities_.at(next_slot_++);
  e.dead = false;
  return e;
}

auto World::removeEntity(Entity& entity) -> void { entity.dead = true; }

auto World::getEntities() -> Storage& { return entities_; }

}  // namespace wr