#pragma once

#include <string>
#include <cstdint>
#include <SDL.h>
#include <entt/entt.hpp>

struct WindowSettings
{
	std::string Title = "WaveRush";
	uint32_t Width = 1280;
	uint32_t Height = 720;
};

class Game
{
 private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	WindowSettings m_Settings;

	bool m_Running;

 private:
	Game();

	~Game();

 public:
	static Game& Instance();

	void Run();

 private:
	void ProcessEvents(SDL_Event& p_Event);

	void ProcessUpdate(float p_DeltaTime);

	void ProcessRender(SDL_Renderer* p_Renderer);

 public:
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;
};
