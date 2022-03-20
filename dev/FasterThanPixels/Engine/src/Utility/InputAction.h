#pragma once
#include "SFML/Graphics.hpp"
namespace Engine {
	enum Trigger {
		KeyDown,
		KeyUp
	};
class InputAction {
public:
	InputAction();
	InputAction(Trigger tr, std::string name, int key);
	Trigger TriggerEvent;
	std::string Name;
	int Keycode;
};
}