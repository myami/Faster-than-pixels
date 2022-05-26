#pragma once
#include <vector>
#include <string>
#include "StateMachine.h"
namespace Engine {
	class FSM_State;
	class StateMachine;
	class FiniteStateMachine : public StateMachine {
	public:
		/*!
		*  \brief constructeur
		*
		*  init la statemachine
		*
		*/
		FiniteStateMachine();
		FSM_State* Initial_States; /*!< State inital */
		FSM_State* Current_States;/*!< State actuelles */
		std::vector<FSM_State*> StatesList; /*!< Vector de listes */
		bool Continued; /*!< bool si on continue a faire tourner la fsm */
		void Add_States(FSM_State* newstate);
		void Reset_FSM();
		void Transit_To(FSM_State* nextstate);
		void Run_FSM(bool reset);
		void Stop_FSM();
		FSM_State* FindByName(std::string name);
	};
}
