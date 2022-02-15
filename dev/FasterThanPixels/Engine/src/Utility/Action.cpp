#include "Action.h"

Engine::Action::Action()
{
}

Engine::Action::Action(std::string name, EtatAction etat)
{
	this->Name = name;
	this->Etat = etat;
}

std::string& Engine::Action::GetName()
{
	return Name;
}

Engine::EtatAction& Engine::Action::GetEtat()
{
	return Etat;
}

