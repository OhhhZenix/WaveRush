#include <memory>

#include "WaveRush/Game.hpp"

int main() {
    auto instance = std::make_unique<WaveRush::Game>();
    instance->Run();
    return 0;
}
