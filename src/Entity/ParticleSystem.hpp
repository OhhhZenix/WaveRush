#pragma once

#include "Entity/Entity.hpp"
#include "Math/Vec2.hpp"
#include <vector>

struct ParticleDescriptor
{
	float Lifetime;
	float MinVelocity;
	float MaxVelocity;
	SDL_Color InitialColor;
	SDL_Color FinalColor;
	Vec2f InitialSize;
	Vec2f FinalSize;

	explicit ParticleDescriptor(
		float p_Lifetime = 10,
		float p_MinVel = 10,
		float p_MaxVel = 10,
		SDL_Color p_InitialCol = {0, 0, 0, 255},
		SDL_Color p_FinalCol = {0, 0, 0, 255},
		Vec2f p_InitialSize = Vec2f(),
		Vec2f p_FinalSize = Vec2f()
		)
		:Lifetime(p_Lifetime), MinVelocity(p_MinVel), MaxVelocity(p_MaxVel), 
		InitialColor(p_InitialCol),	FinalColor(p_FinalCol), InitialSize(p_InitialSize),
		FinalSize(p_FinalSize){};
};

struct Particle
{
	Vec2f Position = Vec2f();
	Vec2f Velocity = Vec2f();
	float Life = 0;
	float Delay = 0;
};

class ParticleSystem : public Entity
{
 private:
	std::vector<Particle> m_ParticleList;

	Entity *m_Hook = nullptr;

	ParticleDescriptor m_ParticleDesc;


 public:
	explicit ParticleSystem(
		const Vec2f& p_Position = Vec2f(),
		size_t p_ParticleNum = 1, 
		const ParticleDescriptor& p_ParticleDesc = ParticleDescriptor()
		);

	void ProcessUpdate(float p_DeltaTime) override;

	void ProcessRender(SDL_Renderer* p_Renderer) override;

	void SetHook(Entity *entity);
};