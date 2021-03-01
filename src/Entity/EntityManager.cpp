#include "EntityManager.hpp"

void EntityManager::AddEntity(Entity* p_Entity)
{
	m_Entities.emplace_back(p_Entity);
}

void EntityManager::RemoveEntity(Entity* p_Entity)
{
	auto f_Iterator = std::find(m_Entities.begin(), m_Entities.end(), p_Entity);
	if (f_Iterator != m_Entities.end())
		m_Entities.erase(f_Iterator);
}

std::vector<Entity*>& EntityManager::GetEntities()
{
	return m_Entities;
}

void EntityManager::ProcessEvents(SDL_Event& p_Event)
{
	if (m_Entities.empty())
		return;

	for (Entity* f_Entity : m_Entities)
		f_Entity->ProcessEvents(p_Event);
}

void EntityManager::ProcessUpdate(float p_DeltaTime)
{
	if (m_Entities.empty())
		return;

	for (Entity* f_Entity : m_Entities)
		f_Entity->ProcessUpdate(p_DeltaTime);
}

void EntityManager::ProcessRender(SDL_Renderer* p_Renderer)
{
	if (m_Entities.empty())
		return;

	for (Entity* f_Entity : m_Entities)
		f_Entity->ProcessRender(p_Renderer);
}