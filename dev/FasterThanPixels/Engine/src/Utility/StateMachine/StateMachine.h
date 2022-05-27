#pragma once
#include <vector>
#include <string>
namespace Engine {
	class StateParent;
	/*! \class StateMachine
	* \brief classe de statemachine
	*
	*/
	class StateMachine {
	public:
		StateMachine();
		std::vector<StateParent*> StatesList; /*!< Vector d'etat */
		bool Continued; /*!< bool si on continue a faire tourner la fsm */
		void Add_States(StateParent* newstate);
		void Reset_FSM();
		void Run_FSM(bool reset);
	};
}
