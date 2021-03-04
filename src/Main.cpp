#include "Core/Game.hpp"
#include "Scene/PlayScene.hpp"

// This kind of setup is need for SDL or else it will fail
int main(int argc, char* argv[]) {
	// Unused argc, argv
	(void)argc;
	(void)argv;

	// Game Instance
	auto& f_Instance = Game::Instance();

	// Init
	f_Instance.GetFontManager().LoadFont("assets/fonts/JetBrainsMono.ttf");
	f_Instance.GetFontManager().LoadFont("assets/fonts/Alphakind.ttf");
	f_Instance.GetSceneManager().SetActiveScene(new PlayScene());

	// Runs the game
	f_Instance.Run();

	// Exit the program
	return 0;
}
