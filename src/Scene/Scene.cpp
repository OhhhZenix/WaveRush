#include "Scene.hpp"

EntityManager& Scene::GetEntityManager()
{
    return m_EntityManager;
}

void Scene::ProcessEvents(SDL_Event& p_Event)
{
}

void Scene::ProcessUpdate(float p_DeltaTime)
{
}

void Scene::ProcessRender(SDL_Renderer* p_Renderer)
{
}
