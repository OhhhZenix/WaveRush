#include "Game.hpp"

#include <iostream>

#include "entities/Player.hpp"
#include "Timer.hpp"

Game::Game()
{
    if (SDL_Init(SDL_INIT_VIDEO > 0))
    {
        // Error Handle
        std::exit(EXIT_FAILURE);
    }

    SDL_Log("Hello World");

    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

    m_Window = SDL_CreateWindow(m_Settings.Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Settings.Width, m_Settings.Height, SDL_WINDOW_SHOWN);

    if (m_Window == nullptr)
    {
        // Error Handle
        std::exit(EXIT_FAILURE);
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

    if (m_Renderer == nullptr)
    {
        // Error Handle
        std::exit(EXIT_FAILURE);
    }

    m_Running = true;
}

Game::~Game()
{
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
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
    	m_EntityManager.Spawn(EntityType::SmartEnemy, 1);
        m_EntityManager.Spawn(EntityType::Player, 1);
        m_EntityManager.Spawn(EntityType::BasicEnemy, 4);
    }

    // Loop
    {
        Timer f_DeltaTimer;
        SDL_Event f_Event;
        double f_DeltaTime;

        f_DeltaTimer.Start();
        while (m_Running)
        {
            // Handle events
            {
                while (SDL_PollEvent(&f_Event))
                {
                    ProcessEvent(&f_Event);
                }
            }

            // Handles updating everything in the game
            ProcessUpdate(f_DeltaTime);

            // Resets the delta time
            f_DeltaTime = static_cast<double>(f_DeltaTimer.GetTicks() / 1000.0);
            f_DeltaTimer.Start();

            // Handles rendering everything in the game
            {
                SDL_SetRenderDrawColor(m_Renderer, 123, 86, 255, 255);
                SDL_RenderClear(m_Renderer);
                ProcessRender(m_Renderer);
                SDL_RenderPresent(m_Renderer);
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

void Game::ProcessEvent(SDL_Event *p_Event)
{
    m_EntityManager.ProcessEvent(p_Event);
    if (p_Event->type == SDL_QUIT)
        m_Running = false;
}

void Game::ProcessUpdate(const double p_DeltaTime)
{
    m_EntityManager.ProcessUpdate(p_DeltaTime);
}

void Game::ProcessRender(SDL_Renderer *p_Renderer)
{
    m_EntityManager.ProcessRender(p_Renderer);
}