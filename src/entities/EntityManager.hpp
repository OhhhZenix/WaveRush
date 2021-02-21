#pragma once

#include <vector>

#include "Entity.hpp"

class EntityManager
{
private:
    std::vector<Entity *> entities;

public:
    ~EntityManager();

    void process_update(const double deltaTime);

    void process_render(sf::RenderWindow *window);

    void spawn(EntityType entityType, uint32_t amount);

    std::vector<Entity *> get_all_entity_with(EntityType type);
};