#include "EntityManager.hpp"

#include "Player.hpp"

void EntityManager::process_update(const double deltaTime)
{
    if (this->entities.empty())
        return;
    for (Entity *entity : this->entities)
    {
        entity->process_update(deltaTime);
    }
}

void EntityManager::process_render(sf::RenderWindow *window)
{
    if (this->entities.empty())
        return;
    for (Entity *entity : this->entities)
    {
        entity->process_render(window);
    }
}

void EntityManager::spawn(EntityID entityID, uint32_t amount)
{
    for (int i = 0; i < amount; i++)
    {
        switch (entityID)
        {
        case EntityID::Player:
            Player *player = new Player();
            this->entities.push_back(std::move(player));
            break;
        }
    }
}