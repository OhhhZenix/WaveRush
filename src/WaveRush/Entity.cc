#include "WaveRush/Entity.h"

namespace wr {

  Entity::~Entity() { alive_ = true; }

  bool Entity::IsAlive() const { return alive_; }

  void Entity::SetAlive(bool value) { alive_ = value; }

} // namespace wr