#pragma once
#include "FSM_State.h"
#include <vector>
class FiniteStateMachine
{
	FSM_State* Initial_States;
	FSM_State* Current_States;
	std::vector<FSM_State*> StatesList;
	bool Continued;
	void Add_States(FSM_State* newstate);
	void Reset_FSM();
	void Transit_To(FSM_State* nextstate);
	void Run_FSM(bool reset);
	void Stop_FSM();

};

