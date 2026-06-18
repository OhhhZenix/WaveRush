#include "PlayScene.hpp"

#include "WaveRush/Entity/BasicEnemy.hpp"
#include "WaveRush/Entity/ParticleSystem.hpp"
#include "WaveRush/Entity/Player.hpp"
#include "WaveRush/Entity/SmartEnemy.hpp"
#include "WaveRush/GUI/Text.hpp"

PlayScene::PlayScene() {
	ParticleDescriptor f_EnemyParticle =
			ParticleDescriptor(
					0.1, 5, 10,
					{ 255, 0, 0, 255 },
					{ 255, 255, 0, 0 },
					glm::vec2(25, 25),
					glm::vec2(5, 5));

	ParticleDescriptor f_PlayerParticle =
			ParticleDescriptor(
					0.3, 5, 10,
					{ 0, 255, 0, 255 },
					{ 0, 0, 255, 0 },
					glm::vec2(50, 50),
					glm::vec2(10, 10));

	// Entity
	auto f_Player = GetEntityManager().AddEntity(new Player(glm::vec2(500, 500)));
	f_Player->SetLayer(5);

	auto f_PlayerParticleSystem = reinterpret_cast<ParticleSystem*>(GetEntityManager().AddEntity(new ParticleSystem(glm::vec2(100, 100), 200, f_PlayerParticle)));
	f_PlayerParticleSystem->SetHook(f_Player);

	for (int i = 0; i < 10; ++i) {
		auto f_Enemy = GetEntityManager().AddEntity(new BasicEnemy());
		f_Enemy->SetLayer(1);

		auto f_ParticleSystem = reinterpret_cast<ParticleSystem*>(GetEntityManager().AddEntity(new ParticleSystem(glm::vec2(100, 100), 200, f_EnemyParticle)));
		f_ParticleSystem->SetHook(f_Enemy);
	}

	for (int i = 0; i < 10; ++i) {
		GetEntityManager().AddEntity(new SmartEnemy());
	}

	// GUI
	GetWidgetManager().AddWidget(new Text(glm::vec2(0, 0), "assets/fonts/JetBrainsMono.ttf", "Cool asdasdasdasd", { 0, 0, 0, 255 }));
}