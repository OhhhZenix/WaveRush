#pragma once

#include <SFML/Graphics.hpp>

enum class EntityID
{
    Player,
    BasicEnemy,
    SmartEnemy
};

class Entity
{
private:
    EntityID entityID;

public:
    Entity(EntityID entityID);

    EntityID get_entity_id() const;

    virtual void process_update(const double deltaTime);

    virtual void process_render(sf::RenderWindow *window);
};