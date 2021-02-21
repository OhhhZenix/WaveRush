#include "Entity.hpp"

Entity::Entity(EntityType entityType)
{
    this->entityType = entityType;
}

EntityType Entity::get_entity_type() const
{
    return this->entityType;
}

void Entity::process_update(const double deltaTime) {}

void Entity::process_render(sf::RenderWindow *window) {}