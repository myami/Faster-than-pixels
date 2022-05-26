#include "BlankComponent.h"
#include <iostream>

Engine::BlankComponent::BlankComponent(std::string na) : Engine::Component(na)
{
}

void Engine::BlankComponent::PrintName()
{
	std::cout << C_Name << std::endl;
}
