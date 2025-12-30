#include "WaveRush/Utils.hpp"
#include <chrono>
#include <random>


int GenerateRandomIntRange(int min, int max) {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    auto dist = std::uniform_int_distribution<int>(min, max);
    return dist(rng);
}
