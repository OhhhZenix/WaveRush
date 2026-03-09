#pragma once

#include <cstddef>
#include <unordered_map>
#include <vector>

namespace WaveRush {
template<typename K, typename V>
class SparseSet {
  public:
    // Adds a new key-value pair if the key does not already exist
    auto add(K key, V value) -> void {
        if (sparse_.find(key) == sparse_.end()) {
            size_t index = dense_.size();
            sparse_[key] = index; // Map the key to the index in the data vector
            dense_.push_back(value); // Store the value in the data vector
        }
    }

    // Removes the key-value pair corresponding to 'key'
    auto remove(K key) -> void {
        auto it = sparse_.find(key);
        if (it != sparse_.end()) {
            size_t index = it->second;
            size_t last_index = dense_.size() - 1;

            // Only swap if the key is not the last element (avoiding redundant swap)
            if (index != last_index) {
                std::swap(
                    dense_[index],
                    dense_[last_index]
                ); // Swap the values in the vector
                sparse_[sparse_[last_index]] =
                    index; // Update the sparse map for the moved element
            }

            // Erase the key from sparse map and remove the last element from data vector
            sparse_.erase(key);
            dense_.pop_back();
        }
    }

    // Returns a pointer to the value associated with 'key', or nullptr if not found
    auto get(K key) -> V* {
        auto it = sparse_.find(key);
        if (it != sparse_.end()) {
            return &dense_[it->second];
        }
        return nullptr;
    }

    auto data() -> std::vector<V>& {
        return dense_;
    }

  private:
    std::unordered_map<K, size_t> sparse_; // Maps key to index in data_
    std::vector<V> dense_; // Stores actual data values contiguously
};
} // namespace WaveRush