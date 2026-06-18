#pragma once

#include "WaveRush/Entity/Entity.hpp"

struct ParticleDescriptor {
	float Lifetime;
	float MinVelocity;
	float MaxVelocity;
	SDL_Color InitialColor;
	SDL_Color FinalColor;
	glm::vec2 InitialSize;
	glm::vec2 FinalSize;

	explicit ParticleDescriptor(
			float p_Lifetime = 10,
			float p_MinVel = 10,
			float p_MaxVel = 10,
			SDL_Color p_InitialCol = { 0, 0, 0, 255 },
			SDL_Color p_FinalCol = { 0, 0, 0, 255 },
			glm::vec2 p_InitialSize = glm::vec2(),
			glm::vec2 p_FinalSize = glm::vec2());
};

struct Particle {
	glm::vec2 Position = glm::vec2();
	glm::vec2 Velocity = glm::vec2();
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
			const glm::vec2& p_Position = glm::vec2(),
			size_t p_ParticleNum = 1,
			const ParticleDescriptor& p_ParticleDesc = ParticleDescriptor());

	void ProcessUpdate(float p_DeltaTime) override;

	void ProcessRender(SDL_Renderer* p_Renderer) override;

	void SetHook(Entity* entity);
};