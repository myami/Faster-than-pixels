#include "EntityManager.h"

void Engine::EntityManager::GenerateEntity()
{
	for (size_t i = 0; i < M_TotalEntity; i++)
	{
		Entity* en = new Entity(i);
		en->E_CanBeUsed = true;
		M_EntityVector.push_back(en);
		M_EntityMap["Empty"].push_back(en);
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

std::vector<Engine::Entity*> Engine::EntityManager::EntityToDraw()
{
	std::vector<Engine::Entity*> todraw;
	for (size_t i = 0; i < M_EntityVector.size(); i++)
	{
		if (!M_EntityVector[i]->E_CanBeUsed) {
			todraw.push_back(M_EntityVector[i]);
		}
	}
	return todraw;
}

std::vector<Engine::Entity*> Engine::EntityManager::GetAllEntityWithComponent(std::string Component)
{
	std::vector<Engine::Entity*> Entity;

	for (size_t i = 0; i < M_EntityVector.size(); i++)
	{
		if (M_EntityVector[i]->GetComponent(Component) != nullptr) {
			Entity.push_back(M_EntityVector[i]);
		}
	}

	return Entity;
}

void Engine::EntityManager::EntityChangeMap(Engine::Entity* entite, std::string oldmap, std::string newmap)
{
	
		for (size_t i = 0; i < M_EntityMap[oldmap].size(); i++)
		{
			if (M_EntityMap[oldmap][i]->E_Id == entite->E_Id) {
				M_EntityMap[oldmap].erase(M_EntityMap[oldmap].begin() + i);
				M_EntityMap[newmap].push_back(entite);
			}
		}
}
