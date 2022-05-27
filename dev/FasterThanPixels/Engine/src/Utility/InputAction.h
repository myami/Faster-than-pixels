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
		Trigger TriggerEvent; /*!< Le trigger */
		std::string Name; /*!<nom de l input */
		int Keycode;/*!< Le code de l input sur le clavier */
	};
}