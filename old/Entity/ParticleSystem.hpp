#pragma once

#include "Entity/Entity.hpp"
#include "Math/Vec2.hpp"

struct ParticleDescriptor {
	float Lifetime;
	float MinVelocity;
	float MaxVelocity;
	SDL_Color InitialColor;
	SDL_Color FinalColor;
	Vec2<float> InitialSize;
	Vec2<float> FinalSize;

	explicit ParticleDescriptor(
			float p_Lifetime = 10,
			float p_MinVel = 10,
			float p_MaxVel = 10,
			SDL_Color p_InitialCol = { 0, 0, 0, 255 },
			SDL_Color p_FinalCol = { 0, 0, 0, 255 },
			Vec2<float> p_InitialSize = Vec2<float>(),
			Vec2<float> p_FinalSize = Vec2<float>());
};

struct Particle {
	Vec2<float> Position = Vec2<float>();
	Vec2<float> Velocity = Vec2<float>();
	float Life = 0;
	float Delay = 0;
};

class ParticleSystem : public Entity {
private:
	std::vector<Particle> m_ParticleList;
	Entity* m_Hook = nullptr;
	ParticleDescriptor m_ParticleDesc;

public:
	explicit ParticleSystem(
			const Vec2<float>& p_Position = Vec2<float>(),
			size_t p_ParticleNum = 1,
			const ParticleDescriptor& p_ParticleDesc = ParticleDescriptor());

	void ProcessUpdate(float p_DeltaTime) override;

	void ProcessRender(SDL_Renderer* p_Renderer) override;

	void SetHook(Entity* entity);
};