#pragma once
#include <string>
namespace Engine {
	enum EtatAction {
		OnKeyDown,
		OnKeyUp
	};
	enum TypeAction {
		Keyboard,
		Mouse,
		Gamepad
	};
	class Action {
		std::string name;
		EtatAction etat;
		TypeAction type;

	public :
		Action();
		Action(std::string name, EtatAction etat);
		std::string Name;
		EtatAction Etat;
		std::string& GetName();
		EtatAction& GetEtat();


	};


}