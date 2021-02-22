#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "core/WindowSettings.hpp"
#include "entities/EntityManager.hpp"

class Game
{
 private:
	WindowSettings m_Settings;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	EntityManager m_EntityManager;
	bool m_Running;

 private:
	Game();

 public:
	~Game();

	static Game& Instance();

	void Run();

	const WindowSettings* GetSettings() const;

	EntityManager& GetEntityManager();

 private:
	void ProcessEvent(SDL_Event* p_Event);

	void ProcessUpdate(float p_DeltaTime);

	void ProcessRender(SDL_Renderer* p_Renderer);

 public:
	Game(Game const&) = delete;

	void operator=(Game const&) = delete;
};