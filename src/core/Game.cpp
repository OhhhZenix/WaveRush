#include "Game.hpp"

#include <iostream>

Game::Game()
{
    this->window = new sf::RenderWindow(sf::VideoMode(this->settings.width, this->settings.height), this->settings.title);
}

Game::~Game()
{
    delete this->window;
}

Game &Game::instance()
{
    static Game instance;
    return instance;
}

void Game::run()
{
    // Init
    {
        this->entityManager.spawn(EntityType::Player, 1);
        this->entityManager.spawn(EntityType::BasicEnemy, 1);
        this->entityManager.spawn(EntityType::SmartEnemy, 1);
    }

    // Loop
    {
        sf::Clock deltaClock;
        double deltaTime = 0;

        while (this->window->isOpen())
        {
            // Update delta time
            {
                deltaTime = deltaClock.restart().asSeconds();
            }

            // Works with the events incoming
            {
                sf::Event event;
                while (this->window->pollEvent(event))
                {
                    process_event(&event);
                }
            }

            // Update everything in the game
            {
                process_update(deltaTime);
            }

            // Renders everything in the game
            {
                this->window->clear(sf::Color(123, 86, 255));
                process_render(this->window);
                this->window->display();
            }
        }
    }
}

const WindowSettings *Game::get_settings() const
{
    return &(this->settings);
}

sf::RenderWindow *Game::get_window() const
{
    return this->window;
}

EntityManager &Game::get_entity_manager()
{
    return this->entityManager;
}

void Game::process_event(sf::Event *event)
{
    if (event->type == sf::Event::Closed)
        this->window->close();
}

void Game::process_update(const double deltaTime)
{
    this->entityManager.process_update(deltaTime);
}

void Game::process_render(sf::RenderWindow *window)
{
    this->entityManager.process_render(this->window);
}