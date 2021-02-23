#include "PlayScene.hpp"


#include "system/RenderRectShapeSystem.hpp"

PlayScene::PlayScene()
{
	// Add entities
	GetEntityManager().SpawnPlayer(1);

	// Register systems
	GetSystemManager().RegisterSystem(new RenderRectShapeSystem());
}
