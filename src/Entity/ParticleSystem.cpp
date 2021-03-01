#include "ParticleSystem.hpp"
#include "core/Utils.hpp"

ParticleSystem::ParticleSystem(const Vec2f& p_Position, size_t p_ParticleNum, const ParticleDescriptor& p_ParticleDesc) 
: Entity(EntityType::Particle)
{
	m_Position = p_Position;
	m_ParticleList.resize(p_ParticleNum);
	m_ParticleDesc = p_ParticleDesc;

	for (Particle& p : m_ParticleList)
	{
		p.Delay = RandomF(0.1, p_ParticleDesc.Lifetime);
	}
}

void ParticleSystem::ProcessUpdate(float p_DeltaTime)
{
	// Check if hook
	if (m_Hook)
		m_Position = m_Hook->GetPosition() + (m_Hook->GetShape().Size / 2);

	for (Particle& p : m_ParticleList)
	{
		// particle delay;
		if (p.Delay > 0)
		{
			p.Delay -= 1 * p_DeltaTime;
			continue;
		}

		// reset dead particle
		if (p.Life <= 0)
		{
			p.Life = m_ParticleDesc.Lifetime;
			p.Position.Y = m_Position.Y;
			p.Position.X = m_Position.X;
			p.Delay = RandomF(0.0, m_ParticleDesc.Lifetime * 0.5);

			float f_Magnitude = RandomF(
				m_ParticleDesc.MinVelocity,
				m_ParticleDesc.MaxVelocity
				);

			float f_Angle = RandomF(0.1, 2 * 3.1416);

			p.Velocity = Vec2f(
				f_Magnitude * cos(f_Angle),
				f_Magnitude * sin(f_Angle)
			);

			continue;
		}

		p.Position += p.Velocity * p_DeltaTime;
		p.Life -= 1 * p_DeltaTime;
	}
}

void ParticleSystem::ProcessRender(SDL_Renderer* p_Renderer)
{
	for (Particle& p : m_ParticleList)
	{
		if (p.Life <= 0) 
			continue;

		// Correct Resizing
		Vec2f f_Size = Vec2f(
			LerpValue(m_ParticleDesc.FinalSize.X, m_ParticleDesc.InitialSize.X, p.Life / m_ParticleDesc.Lifetime),
			LerpValue(m_ParticleDesc.FinalSize.Y, m_ParticleDesc.InitialSize.Y, p.Life / m_ParticleDesc.Lifetime)
		);

		SDL_Rect f_Rect = {
			(int)(p.Position.X - (f_Size.X / 2)),
			(int)(p.Position.Y - (f_Size.Y / 2)),
			(int)f_Size.X,
			(int)f_Size.Y
		};

		SDL_SetRenderDrawColor(
			p_Renderer,
			LerpValue(m_ParticleDesc.FinalColor.r , m_ParticleDesc.InitialColor.r , p.Life / m_ParticleDesc.Lifetime),
			LerpValue(m_ParticleDesc.FinalColor.g , m_ParticleDesc.InitialColor.g , p.Life / m_ParticleDesc.Lifetime),
			LerpValue(m_ParticleDesc.FinalColor.b , m_ParticleDesc.InitialColor.b , p.Life / m_ParticleDesc.Lifetime),
			LerpValue(m_ParticleDesc.FinalColor.a , m_ParticleDesc.InitialColor.a , p.Life / m_ParticleDesc.Lifetime)
			);

		SDL_RenderFillRect(p_Renderer, &f_Rect);
	}
}

void ParticleSystem::SetHook(Entity *entity)
{
	m_Hook = entity;
}
