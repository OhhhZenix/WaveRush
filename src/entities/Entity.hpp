#pragma once

#include <SFML/Graphics.hpp>

enum class EntityType
{
    Player,
    BasicEnemy,
    SmartEnemy,
};

class Entity
{
private:
    EntityType m_EntityType;

public:
    Entity(EntityType p_EntityType);

    EntityType GetEntityType() const;

    virtual void ProcessEvent(sf::Event *p_Event);

    virtual void ProcessUpdate(const double p_DeltaTime);

    virtual void ProcessRender(sf::RenderWindow *p_Window);
};