#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "WaveRush/Entity.hpp"

namespace WaveRush {

using EntityId = uint32_t;
using EntityGen = uint32_t;

struct EntityHandle {
    EntityId index;
    EntityGen generations;
};

class EntityManager {};

} // namespace WaveRush
