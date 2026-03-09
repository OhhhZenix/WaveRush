#pragma once

#include <any>
#include <typeindex>
#include <unordered_map>

namespace WaveRush {

class AnyMap {
  public:
    template<typename T>
    void add() {}

  private:
    std::unordered_map<std::type_index, std::any> data_;
};

} // namespace WaveRush