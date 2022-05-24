#include "Entity.h"

Engine::Entity::Entity(int id)
{
	E_Id = id;
}

Engine::Entity::Entity()
{
}

Engine::Entity::Entity(Scene* sc)
{
	CurrentScene = sc;
}

Engine::Entity::Entity(Scene* sc, std::string tag)
{
	CurrentScene = sc;
	E_Tag = tag;
}

Engine::Entity::Entity(std::string tag)
{
	E_Tag = tag;
}

Engine::Entity::Entity(Scene* sc, std::string tag, int id)
{
	CurrentScene = sc;
	E_Tag = tag;
	E_Id = id;
}

void Engine::Entity::Begin_Play()
{
}

void Engine::Entity::Tick()
{
}

void Engine::Entity::End_Play()
{
}

Engine::Component* Engine::Entity::GetComponent(std::string name)
{
	for (auto compo : E_Component) {
		if (compo->C_Name == name) {
			return compo;
		}
	}
	return nullptr;
}

void Engine::Entity::AddComponent(Engine::Component* cp)
{
	bool notalreadyin = false;
	for (auto compo : E_Component) {
		if (compo->C_Name == cp->C_Name) {
			notalreadyin = true;
		}
	}
	if (!notalreadyin)
		E_Component.push_back(cp);
}

void Engine::Entity::Reset()
{
	E_CanBeUsed = true;
	for (auto const& x : E_Component)
	{
		delete x;
	}
}

void Engine::Entity::DeleteComponent(const std::string name)
{
	for (auto compo : E_Component) {
		if (compo->C_Name == name) {
			delete compo;
		}
	}
}