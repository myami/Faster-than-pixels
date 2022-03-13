#include "Entity.h"

Engine::Component* Engine::Entity::GetComponent(std::string name)
{

	return 	E_Component[name];
}

void Engine::Entity::AddComponent(std::string name, Engine::Component* Component)
{
	E_Component.insert({ name, Component });
}
