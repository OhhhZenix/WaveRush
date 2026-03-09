#pragma once

#include <any>
#include <typeindex>
#include <unordered_map>

namespace WaveRush {

class AnyMap {
  public:
    template<typename T>
    void insert(T item) {
        std::type_index idx = typeid(T);
        data_.insert({idx, std::any(std::move(item))});
    }

    template<typename T>
    T* get() {
        std::type_index idx = typeid(T);
        auto it = data_.find(idx);
        if (it != data_.end()) {
            return std::any_cast<T>(&it->second);
        }
        return nullptr;
    }

  private:
    std::unordered_map<std::type_index, std::any> data_;
};

} // namespace WaveRush