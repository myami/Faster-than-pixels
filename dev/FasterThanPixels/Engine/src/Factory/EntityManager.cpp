#include "EntityManager.h"

Engine::EntityManager::EntityManager()
{

}

void Engine::EntityManager::GenerateEntity()
{


	for (size_t i = 0; i < M_TotalEntity; i++)
	{
		Entity* en = new Entity(i);
		en->E_CanBeUsed = true;
		M_EntityVector.push_back(en);
	}
}

void Engine::EntityManager::Update()
{
	if (AsEntityWaiting()) {
		EntityWaitingListDispatch();
	}
	M_EntityToChange.clear();

}


int Engine::EntityManager::RequestEntity()
{
	for (auto entity : M_EntityVector) {
		if (entity->E_CanBeUsed) {
			entity->E_CanBeUsed = false;
			return entity->E_Id;
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
			AddEntity(delayentity);
			break;
		case Engine::EntityState::Delete:
			RemoveEntity(delayentity);
			break;
		case Engine::EntityState::AddComponent:
			AddComponent(delayentity);
			break;
		case Engine::EntityState::DeleteComponent:
			DeleteComponent(delayentity);
			break;
		default:
			break;
		}
	}
}

void Engine::EntityManager::RemoveEntity(S_Delay_Entity entite)
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == entite.E_ID) 
		{
			entity->Reset();
		}
	}
}

void Engine::EntityManager::AddEntity(S_Delay_Entity entite)
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == entite.E_ID)
		{
			entity->E_CanBeUsed = false;
			entity->E_Tag = entite.E_Tag;
			//EntityChangeMap(entity, entity->E_Tag, entite.E_Tag);
			entity->DeleteComponent("Render");
			entity->E_IsAnimated = entite.IsAnimated;
			for (auto const& x : entite.E_Component)
			{
				entity->AddComponent(x.first, x.second);
			}

		}
	}
}

void Engine::EntityManager::AddComponent(S_Delay_Entity entite) // a ajouter checker si le component existe deja ou pas
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == entite.E_ID)
		{
			for (auto const& x : entite.E_Component)
			{
				
				entity->AddComponent(x.first, x.second);
			}

		}
	}
}

void Engine::EntityManager::DeleteComponent(S_Delay_Entity entite)
{
	for (auto entity : M_EntityVector)
	{
		if (entity->E_Id == entite.E_ID)
		{
			for (auto const& x : entite.E_Component)
			{
				//DeleteComponent(x.first.c_str());
			}

		}
	}
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

Engine::Entity* Engine::EntityManager::GetPlayer()
{
	for (auto entity : M_EntityVector) 
	{
		if (entity->E_Tag == "Player") 
		{
			return entity;
		}
	}
	return nullptr;
}



