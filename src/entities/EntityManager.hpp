#pragma once

#include <vector>

#include "Entity.hpp"

class EntityManager
{
private:
    std::vector<Entity *> entities;

public:
    void process_update(const double deltaTime);

    void process_render(sf::RenderWindow *window);

    void spawn(EntityID entityID, uint32_t amount);
};