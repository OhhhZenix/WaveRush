#include "PlayScene.hpp"

#include "Entity/BasicEnemy.hpp"
#include "Entity/Player.hpp"
#include "Entity/SmartEnemy.hpp"
#include "Entity/ParticleSystem.hpp"

PlayScene::PlayScene()
{
	ParticleDescriptor f_EnemyParticle =
		ParticleDescriptor(
			0.1, 5, 10,
			{255, 0, 0, 255},
			{255, 255, 0, 0},
			Vec2f(25, 25),
			Vec2f(5, 5)
			);

	ParticleDescriptor f_PlayerParticle =
		ParticleDescriptor(
			0.3, 5, 10,
			{0, 255, 0, 255},
			{0, 0, 255, 0},
			Vec2f(50, 50),
			Vec2f(10, 10)
			);


	auto f_Player = GetEntityManager().AddEntity(new Player(Vec2f(500, 500)));
	f_Player->SetLayer(5);

	auto f_PlayerParticleSystem = reinterpret_cast<ParticleSystem *>(GetEntityManager().AddEntity(new ParticleSystem(Vec2f(100, 100), 200, f_PlayerParticle)));
	f_PlayerParticleSystem->SetHook(f_Player);

	for (int i = 0; i < 10; ++i)
	{
		auto f_Enemy = GetEntityManager().AddEntity(new BasicEnemy());
		f_Enemy->SetLayer(1);

		auto f_ParticleSystem = reinterpret_cast<ParticleSystem *>(GetEntityManager().AddEntity(new ParticleSystem(Vec2f(100, 100), 200, f_EnemyParticle)));
		f_ParticleSystem->SetHook(f_Enemy);
	}

	for (int i = 0; i < 10; ++i)
	{
		GetEntityManager().AddEntity(new SmartEnemy());
	}
}