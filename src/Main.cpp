#include <memory>

#include "WaveRush/Game.hpp"
#include "WaveRush/Widget/Button.hpp"

int main() {
    auto but = WaveRush::Button();
    but.OnClick(1, [](){});
    auto instance = std::make_unique<WaveRush::Game>();
    instance->Run();
    return 0;
}
