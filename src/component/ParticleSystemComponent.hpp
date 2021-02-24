#pragma once

#include <SDL.h>
#include <glm/glm.hpp>
#include "component/PositionComponent.hpp"
#include "component/VelocityComponent.hpp"
#include "component/RectangleShapeComponent.hpp"

struct Particle
{
    float Life = 0.0f;
    PositionComponent Position;
    VelocityComponent Velocity;
};

struct ParticleSystemComponent
{
    uint32_t MaxParticles;
    float MaxLifetime;
    float Velocity;
    float Angle;
    RectangleShapeComponent RefShape;
    Particle *Particles;
};
