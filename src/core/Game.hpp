#pragma once

#include <vector>

#include "core/WindowSettings.hpp"

class Game
{
private:
    WindowSettings m_Settings;

private:
    Game();

public:
    ~Game();

    static Game &Instance();

    void Run();

    const WindowSettings *GetSettings() const;

private:
    void ProcessEvent();

    void ProcessUpdate(const double p_DeltaTime);

    void ProcessRender();

public:
    Game(Game const &) = delete;
    void operator=(Game const &) = delete;
};