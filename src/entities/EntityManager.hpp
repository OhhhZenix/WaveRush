#pragma once

#include <vector>

#include "Entity.hpp"

class EntityManager
{
private:
    std::vector<Entity *> m_Entities;

public:
    ~EntityManager();

    void ProcessEvent(sf::Event *p_Event);

    void ProcessUpdate(const double p_DeltaTime);

    void ProcessRender(sf::RenderWindow *p_Window);

    void Spawn(EntityType p_EntityType, uint32_t p_Amount);

    std::vector<Entity *> GetAllEntityWith(EntityType p_EntityType);
};