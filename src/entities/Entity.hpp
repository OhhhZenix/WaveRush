#pragma once

#include <SDL.h>

#include "math/Vector2.hpp"

enum class EntityType {
    Player,
    BasicEnemy,
    SmartEnemy,
};

class Entity {
private:
    EntityType m_EntityType;

protected:
    SDL_Texture *m_Texture;
    SDL_Color m_Color;
    SDL_Color m_OutlineColor;
    int m_OutlineThickness;
    Vector2f m_Position;
    Vector2f m_Velocity;
    Vector2f m_Size;
    bool m_Visibility;

public:
    const EntityType &GetEntityType() const;

    const Vector2f &GetPosition() const;

    const Vector2f &GetVelocity() const;

    const Vector2f &GetSize() const;

    bool IsVisible() const;

    virtual void ProcessEvent(SDL_Event *p_Event);

    virtual void ProcessUpdate(float p_DeltaTime);

    virtual void ProcessRender(SDL_Renderer *p_Renderer);
};