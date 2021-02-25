#include "ParticleSystem.hpp"

#include "component/PositionComponent.hpp"
#include "component/ParticleSystemComponent.hpp"
#include "component/TagComponent.hpp"
#include "core/Utils.hpp"

void ParticleSystem::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
    auto f_View = p_Registry.view<const TagComponent, PositionComponent, ParticleSystemComponent>();
    f_View.each([p_DeltaTime](const TagComponent& f_Tag, PositionComponent& f_Position, ParticleSystemComponent& f_ParticleSystem)
    {
        if (f_Tag.Value == TagType::ParticleSystem)
        {
            if (f_ParticleSystem.MaxParticles == 0)
                return;

            for (int i = 0; i < f_ParticleSystem.MaxParticles; ++i)
            {
                Particle& f_Particle = f_ParticleSystem.Particles[i];
                
                // Chack if delay is not done
                if (f_Particle.Delay > 0){
                    f_Particle.Delay -= 1 * p_DeltaTime;
                    continue;
                }

                // Check if particle is dead
                if (f_Particle.Life <= 0)
                {
                    f_Particle.Position.Value = f_Position.Value;
                    f_Particle.Velocity.Value = glm::vec2(
                        RandomF(-f_ParticleSystem.Velocity, f_ParticleSystem.Velocity),
                        RandomF(-f_ParticleSystem.Velocity, f_ParticleSystem.Velocity)
                    );

                    f_Particle.Life = f_ParticleSystem.MaxLifetime;
                };

                // Add velocity to particle and substract life
                if (f_Particle.Life > 0)
                {
                    f_Particle.Position.Value += f_Particle.Velocity.Value;
                    f_Particle.Life -= 1 * p_DeltaTime;
                }
            }
        }
    });
}

void ParticleSystem::ProcessRender(SDL_Renderer* p_Renderer, entt::registry& p_Registry)
{
    auto f_View = p_Registry.view<const TagComponent, PositionComponent, ParticleSystemComponent>();
    f_View.each([p_Renderer](const TagComponent& f_Tag, PositionComponent& f_Position, ParticleSystemComponent& f_ParticleSystem)
    {
        if (f_Tag.Value == TagType::ParticleSystem){
            
            if (f_ParticleSystem.MaxParticles == 0)
                return;

            // Set color to draw

            for (int i = 0; i < f_ParticleSystem.MaxParticles; ++i)
            {
                Particle f_Particle = f_ParticleSystem.Particles[i];
                
                // Check if delay is not done
                if (f_Particle.Delay > 0){
                    continue;
                }

                // Check if particle is dead
                if (f_Particle.Life <= 0)
                    continue;

                // Add velocity to particle and substract life
                if (f_Particle.Life > 0)
                {
                    SDL_SetRenderDrawColor(
                        p_Renderer,
                        LerpValue(f_ParticleSystem.Color.r, f_ParticleSystem.Color2.r, f_Particle.Life /f_ParticleSystem.MaxLifetime),
                        LerpValue(f_ParticleSystem.Color.g, f_ParticleSystem.Color2.g, f_Particle.Life /f_ParticleSystem.MaxLifetime),
                        LerpValue(f_ParticleSystem.Color.b, f_ParticleSystem.Color2.b, f_Particle.Life /f_ParticleSystem.MaxLifetime),
                        LerpValue(f_ParticleSystem.Color.a, f_ParticleSystem.Color2.a, f_Particle.Life /f_ParticleSystem.MaxLifetime)
                    );

                    SDL_Rect f_Rect = {
                        (int)f_Particle.Position.Value.x,
                        (int)f_Particle.Position.Value.y,
                        (int)f_ParticleSystem.RefShape.Size.x,
                        (int)f_ParticleSystem.RefShape.Size.y
                    };

                    SDL_RenderFillRect(p_Renderer, &f_Rect);
                }
            } 
            
        }
    });
}