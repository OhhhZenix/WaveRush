#include "EntityManager.hpp"

#include "Player.hpp"
#include "BasicEnemy.hpp"

EntityManager::~EntityManager()
{
    if (!this->entities.empty())
    {
        for (int i = this->entities.size() - 1; i >= 0; i--)
        {
            Entity *entity = this->entities[i];
            delete entity;
        }
        this->entities.clear();
    }
}

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

void EntityManager::spawn(EntityType entityType, uint32_t amount)
{
    for (int i = 0; i < amount; i++)
    {
        switch (entityType)
        {
        case EntityType::Player:
        {
            Player *player = new Player();
            this->entities.push_back(std::move(player));
            break;
        }
        case EntityType::BasicEnemy:
        {
            BasicEnemy *enemy = new BasicEnemy();
            this->entities.push_back(std::move(enemy));
            break;
        }
        }
    }
}