#pragma once

#include <vector>

#include "core/WindowSettings.hpp"
#include "entities/EntityManager.hpp"

class Game
{
private:
    WindowSettings m_Settings;
    sf::RenderWindow *m_Window;
    EntityManager m_EntityManager;

private:
    Game();

public:
    ~Game();

    static Game &Instance();

    void Run();

    const WindowSettings *GetSettings() const;

    EntityManager &GetEntityManager();

private:
    void ProcessEvent(sf::Event *p_Event);

    void ProcessUpdate(const double p_DeltaTime);

    void ProcessRender(sf::RenderWindow *p_Window);

public:
    Game(Game const &) = delete;
    void operator=(Game const &) = delete;
};