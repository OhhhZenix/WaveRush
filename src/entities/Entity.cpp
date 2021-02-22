#include "Entity.hpp"

Entity::Entity(EntityType p_EntityType)
{
    m_EntityType = p_EntityType;
}

EntityType Entity::GetEntityType() const
{
    return m_EntityType;
}

void Entity::ProcessEvent(sf::Event *p_Event) {}

void Entity::ProcessUpdate(const double p_DeltaTime) {}

void Entity::ProcessRender(sf::RenderWindow *p_Window) {}