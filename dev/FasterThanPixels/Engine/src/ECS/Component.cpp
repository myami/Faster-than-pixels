#include "Component.h"
#include "Entity.h"

Engine::Component::Component()
{
}

Engine::Component::Component(std::string name)
{
	C_Name = name;
}