#pragma once

#include <raylib.h>

#include <string>

#include "WaveRush/Widget.hpp"

namespace WaveRush {

class Label: public Widget {
  public:
    void SetText(std::string text);
    void SetFontSize(int font_size);
    void SetColor(Color color);

    int GetX();
    void SetX(int x);

    int GetY();
    void SetY(int y);

    void Update(Game& game) override;
    void Render() override;

  private:
    std::string text = "";
    int font_size = 12;
    Color color = BLACK;
    int x = 0;
    int y = 0;
};

} // namespace WaveRush
