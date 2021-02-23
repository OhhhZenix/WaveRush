#include "SystemManager.hpp"

SystemManager::~SystemManager()
{
	if (!m_Systems.empty())
	{
		for (size_t i = m_Systems.size() - 1; i >= 0; --i)
		{
			delete m_Systems[i];
		}
		m_Systems.clear();
	}
}

void SystemManager::RegisterSystem(System* p_System)
{
	m_Systems.emplace_back(p_System);
}

void SystemManager::ProcessEvents(SDL_Event& p_Event, entt::registry& p_Registry)
{
	if (m_Systems.empty())
		return;
	for (System* f_System : m_Systems)
	{
		f_System->ProcessEvents(p_Event, p_Registry);
	}
}

void SystemManager::ProcessUpdate(float p_DeltaTime, entt::registry& p_Registry)
{
	if (m_Systems.empty())
		return;
	for (System* f_System : m_Systems)
	{
		f_System->ProcessUpdate(p_DeltaTime, p_Registry);
	}
}

void SystemManager::ProcessRender(SDL_Renderer* p_Renderer, entt::registry& p_Registry)
{
	if (m_Systems.empty())
		return;
	for (System* f_System : m_Systems)
	{
		f_System->ProcessRender(p_Renderer, p_Registry);
	}
}
