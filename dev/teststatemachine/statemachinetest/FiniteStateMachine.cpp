#include "FiniteStateMachine.h"

void FiniteStateMachine::Add_States(FSM_State* newstate)
{
	StatesList.push_back(newstate);
}

void FiniteStateMachine::Reset_FSM()
{
	Stop_FSM();
	Current_States = Initial_States;
	Current_States->Begin_Play();
}

void FiniteStateMachine::Transit_To(FSM_State* nextstate)
{
	Current_States->End_Play();
	Current_States = nextstate;
	Current_States->Begin_Play();
}

void FiniteStateMachine::Run_FSM(bool reset)
{
	if (reset)
		Reset_FSM();
	while (Continued)
	{
		Current_States->Tick();
		if (Current_States->StopState) {
			Continued = false;
		}
	}
}


