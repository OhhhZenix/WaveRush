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
			Entity* f_Entity = m_Entities[i];
			delete f_Entity;
		}
		m_Entities.clear();
	}
}

void EntityManager::ProcessEvent(SDL_Event* p_Event)
{
	if (m_Entities.empty())
		return;
	for (Entity* f_Entity : m_Entities)
	{
		f_Entity->ProcessEvent(p_Event);
	}
}

void EntityManager::ProcessUpdate(const double p_DeltaTime)
{
	if (m_Entities.empty())
		return;
	for (Entity* f_Entity : m_Entities)
	{
		f_Entity->ProcessUpdate(p_DeltaTime);
	}
}

void EntityManager::ProcessRender(SDL_Renderer* p_Renderer)
{
	if (m_Entities.empty())
		return;
	for (Entity* f_Entity : m_Entities)
	{
		f_Entity->ProcessRender(p_Renderer);
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
			m_Entities.emplace_back(new Player());
			break;
		}
		case EntityType::BasicEnemy:
		{
			m_Entities.emplace_back(new BasicEnemy());
			break;
		}
		case EntityType::SmartEnemy:
		{
			m_Entities.emplace_back(new SmartEnemy());
			break;
		}
		default:
			break;
		}
	}
}

std::vector<Entity*> EntityManager::GetAllEntityWith(EntityType p_EntityType)
{
	std::vector<Entity*> f_Request;
	if (m_Entities.empty())
		return f_Request;
	for (int i = m_Entities.size() - 1; i >= 0; i--)
	{
		Entity* f_Entity = m_Entities[i];
		if (f_Entity->GetEntityType() == p_EntityType)
		{
			f_Request.emplace_back(f_Entity);
		}
	}
	return f_Request;
}