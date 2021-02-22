#include "EntityManager.hpp"

#include "Player.hpp"
#include "BasicEnemy.hpp"
#include "SmartEnemy.hpp"

EntityManager::~EntityManager()
{
    if (!m_Entities.empty())
    {
        for (int i = m_Entities.size() - 1; i >= 0; i--)
        {
            Entity *entity = m_Entities[i];
            delete entity;
        }
        m_Entities.clear();
    }
}

void EntityManager::ProcessEvent(sf::Event *p_Event)
{
    if (m_Entities.empty())
        return;
    for (Entity *entity : m_Entities)
    {
        entity->ProcessEvent(p_Event);
    }
}

void EntityManager::ProcessUpdate(const double p_DeltaTime)
{
    if (m_Entities.empty())
        return;
    for (Entity *entity : m_Entities)
    {
        entity->ProcessUpdate(p_DeltaTime);
    }
}

void EntityManager::ProcessRender(sf::RenderWindow *p_Window)
{
    if (m_Entities.empty())
        return;
    for (Entity *entity : m_Entities)
    {
        entity->ProcessRender(p_Window);
    }
}

void EntityManager::Spawn(EntityType p_EntityType, uint32_t p_Amount)
{
    for (int i = 0; i < p_Amount; i++)
    {
        switch (p_EntityType)
        {
        case EntityType::Player:
        {
            Player *player = new Player();
            m_Entities.push_back(std::move(player));
            break;
        }
        case EntityType::BasicEnemy:
        {
            BasicEnemy *basicEnemy = new BasicEnemy();
            m_Entities.push_back(std::move(basicEnemy));
            break;
        }
        case EntityType::SmartEnemy:
        {
            SmartEnemy *smartEnemy = new SmartEnemy();
            m_Entities.push_back(std::move(smartEnemy));
            break;
        }
        default:
            break;
        }
    }
}

std::vector<Entity *> EntityManager::GetAllEntityWith(EntityType p_EntityType)
{
    std::vector<Entity *> request;
    if (m_Entities.empty())
        return request;
    for (int i = m_Entities.size() - 1; i >= 0; i--)
    {
        Entity *entity = m_Entities[i];
        if (entity->GetEntityType() == p_EntityType)
        {
            request.emplace_back(entity);
        }
    }
    return request;
}