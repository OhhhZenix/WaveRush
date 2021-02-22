#include <iostream>
#include "core/Game.hpp"
#include <SDL.h>

/*
- Allow adjustable speed for player (✅)
- Add particle system
- Add death system
- Add different types of enemies
- Parrying system
- Add a store
    - parrying
        - healing
        - split the enemies to double it
*/

/*
struct/class = Pascal
Function = pascal
variables = param -> p_Var, member -> m_Var, function/method var -> f_Var
*/

int main(void)
{
	//Game::Instance().Run();
	//
	SDL_Window *f_Window;
	SDL_Surface *f_ScreenSurface;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL Failed. Error:" << SDL_GetError();
	}

	f_Window = SDL_CreateWindow(
		"WaveRush",
		SDL_WINDOWPOS_UNDEFINED, // x
		SDL_WINDOWPOS_UNDEFINED, // y
		500,					 // Width
		500,					 // Height
		SDL_WINDOW_SHOWN);

	SDL_Delay(5000);

	SDL_DestroyWindow(f_Window);
	SDL_Quit();

	return 0;
}
