#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <glm/glm.hpp>

namespace wr {

enum class EntityType : std::uint32_t {
  Entity = 0,
  Player,
  BasicEnemy,
  SmartEnemy,
  Particle,
};

class Entity {
 public:
  EntityType type;
  glm::vec2 position;
  bool dead;
};

class World {
 public:
  using Storage = std::array<Entity, 1024>;

  auto addEntity() -> Entity&;
  auto removeEntity(Entity& entity) -> void;
  auto getEntities() -> Storage&;

 private:
  Storage entities_;
  std::size_t next_slot_ = 0;
};

}  // namespace wr