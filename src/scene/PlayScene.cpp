#include "PlayScene.hpp"

#include "system/PlayerMovementSystem.hpp"
#include "system/RenderRectShapeSystem.hpp"
#include "system/BasicEnemyMovementSystem.hpp"

PlayScene::PlayScene()
{
	// Add entities
	GetEntityManager().SpawnPlayer(1);
	GetEntityManager().SpawnSmartEnemy(10);
	GetEntityManager().SpawnBasicEnemy(10);

	// Register systems
	GetSystemManager().RegisterSystem(new PlayerMovementSystem());
	GetSystemManager().RegisterSystem(new RenderRectShapeSystem());
	GetSystemManager().RegisterSystem(new BasicEnemyMovementSystem());
}
