#include "PlayScene.hpp"

#include "system/PlayerMovementSystem.hpp"
#include "system/RenderRectShapeSystem.hpp"
#include "system/BasicEnemyMovementSystem.hpp"
#include "system/SmartEnemyMovementSystem.hpp"
#include "system/ParticleSystem.hpp"

PlayScene::PlayScene()
{
	// Add entities
	GetEntityManager().SpawnPlayer(1);
	GetEntityManager().SpawnSmartEnemy(10);
	GetEntityManager().SpawnBasicEnemy(10);
	GetEntityManager().SpawnParticleSystem(10, 0, 1000, 0);

	// Register systems
	GetSystemManager().RegisterSystem(new PlayerMovementSystem());
	GetSystemManager().RegisterSystem(new RenderRectShapeSystem());
	GetSystemManager().RegisterSystem(new BasicEnemyMovementSystem());
	GetSystemManager().RegisterSystem(new SmartEnemyMovementSystem());
	GetSystemManager().RegisterSystem(new ParticleSystem());
}
