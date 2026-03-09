#pragma once

#include <any>
#include <typeindex>
#include <unordered_map>

namespace WaveRush {

class AnyMap {
  public:
    template<typename T>
    auto insert(T item) -> void {
        std::type_index idx = typeid(T);
        data_.insert({idx, std::any(std::move(item))});
    }

    template<typename T>
    auto get() -> std::optional<std::reference_wrapper<T>> {
        std::type_index idx = typeid(T);
        auto it = data_.find(idx);
        if (it != data_.end()) {
            if (auto ptr = std::any_cast<T>(&it->second)) {
                return std::ref(*ptr);
            }
        }
        return std::nullopt;
    }

  private:
    std::unordered_map<std::type_index, std::any> data_;
};

} // namespace WaveRush