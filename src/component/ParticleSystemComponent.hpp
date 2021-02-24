#pragma once

#include <SDL.h>
#include <glm/glm.hpp>
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"
#include "component/RectangleShapeComponent.hpp"

struct Particle
{
    float Life = 0.0f;
    float Delay = 0.0f;
    PositionComponent Position;
    VelocityComponent Velocity;
};

struct ParticleSystemComponent
{
    uint32_t MaxParticles;
    float MaxLifetime;
    float Velocity;

    SDL_Color Color = { 0, 0, 0, 0 };
	SDL_Color Color2 = { 0, 0, 0, 0 };

    RectangleShapeComponent RefShape;
    Particle *Particles;
};
