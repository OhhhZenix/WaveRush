#include "PlayScene.hpp"

#include "Entity/BasicEnemy.hpp"
#include "Entity/Player.hpp"
#include "Entity/SmartEnemy.hpp"

PlayScene::PlayScene()
{
	GetEntityManager().AddEntity(new Player(Vec2f(500, 500)));
	for (int i = 0; i < 10; ++i)
	{
		GetEntityManager().AddEntity(new BasicEnemy());
	}

	for (int i = 0; i < 10; ++i)
	{
		GetEntityManager().AddEntity(new SmartEnemy());
	}
}