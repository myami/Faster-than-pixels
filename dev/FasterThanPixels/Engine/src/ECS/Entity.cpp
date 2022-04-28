#include "Entity.h"

Engine::Entity::Entity(int id)
{
	E_Id = id;
}

Engine::Component* Engine::Entity::GetComponent(std::string name)
{
	return 	E_Component[name];
}

void Engine::Entity::AddComponent(std::string name, Engine::Component* Component)
{
	E_Component.insert({ name, Component });
}

void Engine::Entity::Reset()
{
	E_CanBeUsed = true;
	for (auto const& x : E_Component)
	{
		delete x.second; // je sais pas si le erase le fait
		E_Component.erase(x.first);
		E_Tag = "Default";
		E_IsAnimated = false;
	}
}

void Engine::Entity::DeleteComponent(const std::string name)
{
	delete E_Component[name]; // pas sur de devoir le faire avec le erase
	E_Component.erase(name);
}