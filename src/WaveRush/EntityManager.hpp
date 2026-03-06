#pragma once

#include <memory>
#include <vector>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

using EntityVec = std::vector<std::unique_ptr<Entity>>;

class EntityManager {
  public:
    template<typename T, typename... Args>
    auto AddEntity(Args&&... args) -> T& {
        static_assert(
            std::is_base_of_v<Entity, T>,
            "T must derive from Entity"
        );

        auto& ptr = this->entities_.emplace_back(
            std::make_unique<T>(std::forward<Args>(args)...)
        );

        return static_cast<T&>(*ptr);
    }

    auto GetEntities() -> EntityVec&;

    auto Update(Game& game) -> void;
    auto Render() -> void;

  private:
    EntityVec entities_;
};

} // namespace WaveRush
