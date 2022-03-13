#include "EntityManager.h"

void Engine::EntityManager::GenerateEntity()
{
	for (size_t i = 0; i < M_TotalEntity; i++)
	{
		Entity* en = new Entity();
		M_EntityVector.push_back(en);
	}
}

void Engine::EntityManager::Update()
{
}

void Engine::EntityManager::RemoveEntity()
{
	for (size_t i = 0; i < M_EntityToChange.size(); i++)
	{
		
	}
}

Engine::Entity* Engine::EntityManager::RequestEntity()
{

	for (size_t i = 0; i < M_EntityVector.size(); i++)
	{
		if (M_EntityVector[i]->E_CanBeUsed) {
			return M_EntityVector[i];
		}
	}
	std::cout << "Aucune entite est libre d'utilisation" << std::endl;
	return nullptr; // si il y en a aucune de dispo
	
}
