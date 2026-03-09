#pragma once

#include <cstddef>
#include <optional>

#include "WaveRush/Core/AnyMap.hpp"
#include "WaveRush/Core/SparseSet.hpp"
#include "WaveRush/Entity/EntityManager.hpp"
#include "WaveRush/Utils.hpp"

namespace WaveRush {

template<typename T>
using ComponentSparseSet = SparseSet<EntityId, T>;

class ComponentManager {
  public:
    template<typename T>
    auto registerComponent() -> void {
        components_.insert(ComponentSparseSet<T>());
    }

    // template<typename T>
    // auto getComponents() -> OptionalRef<std::vector<T>> {
    //     auto sparse_set = components_.get<ComponentSparseSet<T>>();
    //     if (sparse_set) {
    //         return sparse_set->get().data();
    //     }
    //     return std::nullopt;
    // }

    template<typename T>
    auto addComponent(size_t entity, T component) -> void {
        auto sparse_set = components_.get<ComponentSparseSet<T>>();
        if (sparse_set) {
            sparse_set->get().add(entity, component);
        }
    }

    template<typename T>
    auto getComponent(size_t entity) -> OptionalRef<T> {
        auto sparse_set = components_.get<ComponentSparseSet<T>>();
        if (sparse_set) {
            return sparse_set->get().get(entity);
        }
        return std::nullopt;
    }

  private:
    AnyMap components_;
};

} // namespace WaveRush