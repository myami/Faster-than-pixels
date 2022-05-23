#include "EntityManager.h"

Engine::EntityManager::EntityManager()
{
}



void Engine::EntityManager::Update()
{
	if (AsEntityWaiting()) {
		EntityWaitingListDispatch();
	}
	M_EntityToChange.clear();
}

int Engine::EntityManager::RequestEntity(std::string tag)
{
	std::vector<int> used_id;
	for (S_Delay_Entity delayentity : M_EntityToChange) 
	{
		used_id.push_back(delayentity.E_ID);
		
	}
	for (auto entity : M_EntityVector) {
		if (entity->E_CanBeUsed) {
			bool notused = false;
			for (int id : used_id) 
			{
				if (entity->E_Id == id)
					notused = true;
			}
			if (!notused)
				if (entity->E_Tag.compare(tag))
					return entity->E_Id;
			// si le id est pas dans la waiting list et il a le tag 
			
		}
	}

	std::cout << "Aucune entite est libre d'utilisation" << std::endl;
	return 0; // si il y en a aucune de dispo
}

std::vector<Engine::Entity*> Engine::EntityManager::EntityToDraw()
{
	std::vector<Engine::Entity*> todraw;

	for (auto entity : M_EntityVector)
	{
		if (entity->GetComponent("Render") != nullptr)
		{
			todraw.push_back(entity);
		}
	}
	return todraw;
}

std::vector<Engine::Entity*> Engine::EntityManager::GetAllEntityWithComponent(std::string Component)
{
	std::vector<Engine::Entity*> Entity;
	for (auto entity : M_EntityVector)
	{
		if (entity->GetComponent(Component) != nullptr) {
			Entity.push_back(entity);
		}
	}

	return Entity;
}

Engine::Entity* Engine::EntityManager::GetEntityWithId(int id)
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == id)
		{
			return entity;
		}
	}
	return nullptr;
}

bool Engine::EntityManager::AsEntityWaiting()
{
	if (M_EntityToChange.size() != 0)
		return true;
	else {
		return false;
	}
}

void Engine::EntityManager::EntityWaitingListDispatch()
{
	for (S_Delay_Entity delayentity : M_EntityToChange)
	{
		switch (delayentity.E_State)
		{
		case Engine::EntityState::Add:
			EntityEndWaiting(AddEntity(delayentity), Engine::EntityState::Add);
			break;
		case Engine::EntityState::Delete:
			EntityEndWaiting(RemoveEntity(delayentity), Engine::EntityState::Delete);
			break;

		default:
			break;
		}
	}
}

Engine::Entity* Engine::EntityManager::RemoveEntity(S_Delay_Entity entite)
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == entite.E_ID)
		{
			entity->End_Play();
			entity->Reset();
			return entity;
		}
	}
	return nullptr;
}

Engine::Entity* Engine::EntityManager::AddEntity(S_Delay_Entity entite)
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == entite.E_ID)
		{
			entity->E_CanBeUsed = false;
			entity->E_Tag = entite.E_Tag;
			entity->E_IsAnimated = entite.IsAnimated;
			entity->Begin_Play();
			Add_States(dynamic_cast<StateParent*>(entity));
			return entity;
		}
	}
	return nullptr;
}


void Engine::EntityManager::AddToWaiting(S_Delay_Entity entite)
{
	M_EntityToChange.push_back(entite);
}

std::vector<Engine::Entity*> Engine::EntityManager::GetAllEntityWithTag(std::string Tag)
{
	std::vector<Engine::Entity*> tmp;
	for (auto entity : M_EntityVector) {
		if (entity->E_Tag == Tag) {
			tmp.push_back(entity);
		}
	}
	return tmp;
}
