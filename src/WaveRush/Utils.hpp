#pragma once

#include <chrono>
#include <random>
#include <type_traits>

template<typename T>
T GenerateRandomRange(T min, T max) {
    static std::mt19937 rng(
        std::chrono::system_clock::now().time_since_epoch().count()
    );

    using Distribution = typename std::conditional<
        std::is_floating_point<T>::value,
        std::uniform_real_distribution<T>,
        std::uniform_int_distribution<T>>::type;

    Distribution dist(min, max);
    return dist(rng);
}
