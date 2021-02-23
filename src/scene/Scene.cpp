#include "Scene.hpp"

SystemManager& Scene::GetSystemManager()
{
	return m_SystemManager;
}

EntityManager& Scene::GetEntityManager()
{
	return m_EntityManager;
}

void Scene::ProcessEvents(SDL_Event& p_Event)
{
	// No need to fill it out
}

void Scene::ProcessUpdate(float p_DeltaTime)
{
	// No need to fill it out
}

void Scene::ProcessRender(SDL_Renderer* p_Renderer)
{
	// No need to fill it out
}
