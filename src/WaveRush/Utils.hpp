#pragma once

#include <chrono>
#include <random>
#include <type_traits>

template<typename T>
T GenerateRandomRange(T min, T max) {
    static std::mt19937 rng(
        static_cast<unsigned>(
            std::chrono::system_clock::now().time_since_epoch().count()
        )
    );

    if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(min, max);
        return dist(rng);
    } else if constexpr (std::is_integral_v<T>) {
        using DistType = std::conditional_t<(sizeof(T) < sizeof(int)), int, T>;

        std::uniform_int_distribution<DistType> dist(
            static_cast<DistType>(min),
            static_cast<DistType>(max)
        );

        return static_cast<T>(dist(rng));
    }
}
