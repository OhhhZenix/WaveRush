#include "Scene.hpp"

SystemManager& Scene::GetSystemManager()
{
	return m_SystemManager;
}

EntityManager& Scene::GetEntityManager()
{
	return m_EntityManager;
}

void Scene::ProcessUpdate(float p_DeltaTime)
{
}
