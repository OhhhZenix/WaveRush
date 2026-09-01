#pragma once

#include <cstdint>

namespace wr
{

constexpr std::int32_t GAME_WIDTH = 640;
constexpr std::int32_t GAME_HEIGHT = 360;
constexpr const char *GAME_TITLE = "Wave Rush";

constexpr std::int32_t MAX_QUADS = 1000;
constexpr std::int32_t VERTICES_PER_QUAD = 4;
constexpr std::int32_t MAX_QUAD_VERTICES = MAX_QUADS * wr::VERTICES_PER_QUAD;
constexpr std::int32_t INDICES_PER_QUAD = 6;
constexpr std::int32_t MAX_QUAD_INDICES = MAX_QUADS * wr::INDICES_PER_QUAD;

} // namespace wr