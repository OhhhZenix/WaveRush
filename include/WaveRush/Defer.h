#pragma once

static inline void _cleanup_block(void (^*block)(void)) {
  if (*block)
    (*block)();
}

#define defer_concat_impl(x, y) x##y
#define defer_concat(x, y) defer_concat_impl(x, y)
#define defer                                                                                                          \
  void (^defer_concat(_defer_block_, __LINE__))(void) __attribute__((cleanup(_cleanup_block)))                         \
  __attribute__((unused)) = ^
