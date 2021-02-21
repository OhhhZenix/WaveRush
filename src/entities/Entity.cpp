#include "Entity.hpp"

Entity::Entity(EntityID entityID)
{
    this->entityID = entityID;
}

EntityID Entity::get_entity_id() const
{
    return this->entityID;
}

void Entity::process_update(const double deltaTime) {}

void Entity::process_render(sf::RenderWindow *window) {}