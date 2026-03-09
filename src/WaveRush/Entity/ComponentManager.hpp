#pragma once

#include <cstddef>

#include "WaveRush/Core/AnyMap.hpp"
#include "WaveRush/Core/SparseSet.hpp"

namespace WaveRush {

class ComponentManager {
  public:
    void registerComponent() {
        components_.insert(SparseSet<size_t, size_t>());
    }

    void getComponentArray() {}

  private:
    AnyMap components_;
};

} // namespace WaveRush