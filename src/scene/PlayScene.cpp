#include "PlayScene.hpp"

#include "system/PlayerMovementSystem.hpp"
#include "system/RenderRectShapeSystem.hpp"

PlayScene::PlayScene()
{
	// Add entities
	GetEntityManager().SpawnPlayer(1);
	GetEntityManager().SpawnBasicEnemy(1);

	// Register systems
	GetSystemManager().RegisterSystem(new PlayerMovementSystem());
	GetSystemManager().RegisterSystem(new RenderRectShapeSystem());
}
