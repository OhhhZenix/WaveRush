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
    EntityType entityType;

public:
    Entity(EntityType entityType);

    EntityType get_entity_type() const;

    virtual void process_event(sf::Event *event);

    virtual void process_update(const double deltaTime);

    virtual void process_render(sf::RenderWindow *window);
};