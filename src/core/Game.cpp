#include "Game.hpp"

#include <iostream>

Game::Game()
{
    m_Window = new sf::RenderWindow(sf::VideoMode(m_Settings.Width, m_Settings.Height), m_Settings.Title);
}

Game::~Game()
{
    delete m_Window;
}

Game &Game::Instance()
{
    static Game s_Instance;
    return s_Instance;
}

void Game::Run()
{
    // Init
    {
        m_EntityManager.Spawn(EntityType::Player, 1);
        m_EntityManager.Spawn(EntityType::BasicEnemy, 10);
        m_EntityManager.Spawn(EntityType::SmartEnemy, 10);
    }

    // Loop
    {
        sf::Clock f_DeltaClock;
        double f_DeltaTime = 0;

        while (m_Window->isOpen())
        {
            // Update delta time
            {
                f_DeltaTime = f_DeltaClock.restart().asSeconds();
            }

            // Works with the events incoming
            {
                sf::Event f_Event;
                while (m_Window->pollEvent(f_Event))
                {
                    ProcessEvent(&f_Event);
                }
            }

            // Update everything in the game
            {
                ProcessUpdate(f_DeltaTime);
            }

            // Renders everything in the game
            {
                m_Window->clear(sf::Color(123, 86, 255));
                ProcessRender(m_Window);
                m_Window->display();
            }
        }
    }
}

const WindowSettings *Game::GetSettings() const
{
    return &m_Settings;
}

EntityManager &Game::GetEntityManager()
{
    return m_EntityManager;
}

void Game::ProcessEvent(sf::Event *p_Event)
{
    m_EntityManager.ProcessEvent(p_Event);
    if (p_Event->type == sf::Event::Closed)
        m_Window->close();
}

void Game::ProcessUpdate(const double p_DeltaTime)
{
    m_EntityManager.ProcessUpdate(p_DeltaTime);
}

void Game::ProcessRender(sf::RenderWindow *p_Window)
{
    m_EntityManager.ProcessRender(p_Window);
}