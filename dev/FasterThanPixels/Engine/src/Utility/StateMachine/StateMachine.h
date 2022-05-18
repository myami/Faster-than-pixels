#pragma once
#include <vector>
#include <string>
namespace Engine {
	class StateParent;
	class StateMachine{
	public:
		StateMachine();
		std::vector<StateParent*> StatesList;
		bool Continued;
		void Add_States(StateParent* newstate);
		void Reset_FSM();
		void Run_FSM(bool reset);

	};
}


