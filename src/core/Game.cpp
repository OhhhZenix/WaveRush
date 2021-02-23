#include "Game.hpp"

#include <iostream>

Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::exit(EXIT_FAILURE);

	m_Window = SDL_CreateWindow(m_Settings.Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Settings
		.Width, m_Settings.Height, SDL_WINDOW_SHOWN);

	if (m_Window == nullptr)
		std::exit(EXIT_FAILURE);

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);

	if (m_Renderer == nullptr)
		std::exit(EXIT_FAILURE);

	m_ActiveScene = new Scene();

	m_Running = true;
}

Game::~Game()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

Game& Game::Instance()
{
	static Game s_Instance;
	return s_Instance;
}

void Game::Run()
{
	SDL_Event f_Event;

	while (m_Running)
	{
		// Event related work
		{
			while (SDL_PollEvent(&f_Event))
			{
				ProcessEvents(f_Event);
			}
		}

		// Update related work
		{
			// TODO: Impl delta time
			ProcessUpdate(1.0f);
		}

		// Render related work
		{
			// Set clear color
			SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

			// Clear screen
			SDL_RenderClear(m_Renderer);

			// Renders everything
			ProcessRender(m_Renderer);

			// Update screen
			SDL_RenderPresent(m_Renderer);
		}
	}
}

void Game::ProcessEvents(SDL_Event& p_Event)
{
	m_ActiveScene->GetSystemManager().ProcessEvents(p_Event, m_ActiveScene->GetEntityManager().GetRegistry());
	if (p_Event.type == SDL_QUIT)
		m_Running = false;
}

void Game::ProcessUpdate(float p_DeltaTime)
{
	m_ActiveScene->ProcessUpdate(p_DeltaTime);
	m_ActiveScene->GetSystemManager().ProcessUpdate(p_DeltaTime, m_ActiveScene->GetEntityManager().GetRegistry());
}

void Game::ProcessRender(SDL_Renderer* p_Renderer)
{
	m_ActiveScene->GetSystemManager().ProcessRender(p_Renderer, m_ActiveScene->GetEntityManager().GetRegistry());
}