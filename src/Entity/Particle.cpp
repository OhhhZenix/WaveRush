#include "Particle.hpp"

Particle::Particle(const Vec2f& p_Position) : Entity(EntityType::Particle)
{
	m_Position = p_Position;
}

void Particle::ProcessUpdate(float p_DeltaTime)
{
	Entity::ProcessUpdate(p_DeltaTime);
}
