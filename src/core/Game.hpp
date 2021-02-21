#pragma once

#include <vector>

#include "core/WindowSettings.hpp"
#include "entities/EntityManager.hpp"

class Game
{
private:
    WindowSettings settings;
    sf::RenderWindow *window;
    EntityManager entityManager;

private:
    Game();

public:
    ~Game();

    static Game &instance();

    void run();

    const WindowSettings *get_settings() const;

    sf::RenderWindow *get_window() const;

    EntityManager &get_entity_manager();

private:
    void process_event(sf::Event *event);

    void process_update(const double deltaTime);

    void process_render(sf::RenderWindow *window);

public:
    Game(Game const &) = delete;
    void operator=(Game const &) = delete;
};