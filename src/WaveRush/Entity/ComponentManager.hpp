#pragma once

#include <cstddef>
#include <vector>

#include "WaveRush/Core/AnyMap.hpp"
#include "WaveRush/Core/SparseSet.hpp"

namespace WaveRush {

class ComponentManager {
  public:
    template<typename T>
    void registerComponent() {
        components_.insert(SparseSet<size_t, T>());
    }

    template<typename T>
    std::vector<T>* getComponentArray() {
        auto sparse_set = components_.get<SparseSet<size_t, T>>();
        if (sparse_set) {
            return &sparse_set->data();
        }
        return nullptr;
    }

  private:
    AnyMap components_;
};

} // namespace WaveRush