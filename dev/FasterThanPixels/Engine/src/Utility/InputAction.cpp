#include "InputAction.h"

Engine::InputAction::InputAction()
{
}

Engine::InputAction::InputAction(Trigger tr, std::string name, int key)
{
	this->TriggerEvent = tr;
	this->Name = name;
	this->Keycode = key;
}