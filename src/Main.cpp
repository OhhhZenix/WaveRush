#include <memory>

#include "WaveRush/Game.hpp"

auto main() -> int {
    auto instance = std::make_unique<WaveRush::Game>();
    instance->Run();
    return 0;
}
