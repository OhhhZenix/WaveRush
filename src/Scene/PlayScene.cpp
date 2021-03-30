#include "PlayScene.hpp"

#include "Entity/BasicEnemy.hpp"
#include "Entity/ParticleSystem.hpp"
#include "Entity/Player.hpp"
#include "Entity/SmartEnemy.hpp"
#include "GUI/Text.hpp"

PlayScene::PlayScene() {
	ParticleDescriptor f_EnemyParticle =
			ParticleDescriptor(
					0.1, 5, 10,
					{ 255, 0, 0, 255 },
					{ 255, 255, 0, 0 },
					Vec2<float>(25, 25),
					Vec2<float>(5, 5));

	ParticleDescriptor f_PlayerParticle =
			ParticleDescriptor(
					0.3, 5, 10,
					{ 0, 255, 0, 255 },
					{ 0, 0, 255, 0 },
					Vec2<float>(50, 50),
					Vec2<float>(10, 10));

	// Entity
	auto f_Player = GetEntityManager().AddEntity(new Player(Vec2<float>(500, 500)));
	f_Player->SetLayer(5);

	auto f_PlayerParticleSystem = reinterpret_cast<ParticleSystem*>(GetEntityManager().AddEntity(new ParticleSystem(Vec2<float>(100, 100), 200, f_PlayerParticle)));
	f_PlayerParticleSystem->SetHook(f_Player);

	for (int i = 0; i < 10; ++i) {
		auto f_Enemy = GetEntityManager().AddEntity(new BasicEnemy());
		f_Enemy->SetLayer(1);

		auto f_ParticleSystem = reinterpret_cast<ParticleSystem*>(GetEntityManager().AddEntity(new ParticleSystem(Vec2<float>(100, 100), 200, f_EnemyParticle)));
		f_ParticleSystem->SetHook(f_Enemy);
	}

	for (int i = 0; i < 10; ++i) {
		GetEntityManager().AddEntity(new SmartEnemy());
	}

	// GUI
	GetWidgetManager().AddWidget(new Text(Vec2<float>(0, 0), "assets/fonts/JetBrainsMono.ttf", 10, "Cool asdasdasdasd", { 0, 0, 0, 255 }));
}