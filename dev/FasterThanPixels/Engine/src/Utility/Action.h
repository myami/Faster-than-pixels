#pragma once
#include <string>
namespace Engine {
	enum EtatAction {
		OnKeyDown,
		OnKeyUp
	};
	class Action {
		std::string name;
		EtatAction etat;
	public :
		Action();
		Action(std::string name, EtatAction etat);
		std::string& GetName();
		EtatAction& GetEtat();


	};


}