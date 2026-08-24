#pragma once

#include <glm/glm.hpp>

namespace wr {

class App {
 public:
  App();
  ~App();
  App(const App&) = delete;
  App& operator=(const App&) = delete;
  App(App&&) = delete;
  App& operator=(App&&) = delete;
  void run();

 private:
  bool running_;
};

};  // namespace wr