#include "FiniteStateMachine.h"

void FiniteStateMachine::Add_States(FSM_State* newstate)
{
	StatesList.push_back(newstate);
}

void FiniteStateMachine::Reset_FSM()
{
	Current_States = Initial_States;
	Current_States->Begin_Play();
	Continued = true;
	Run_FSM(false);

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
		if (Current_States->param.StopState) {
			if (Current_States->param.isterminal)
			{
				Continued = false;
				Stop_FSM();
			}
				
			else {
				Transit_To(FindByName(Current_States->param.NextScene));
			}
		}
	}
}

void FiniteStateMachine::Stop_FSM()
{
	Current_States->End_Play();
}

FSM_State* FiniteStateMachine::FindByName(std::string name)
{
	for (FSM_State* state : StatesList)
	{
		if (state->param.StateName == name) {
			return state;
		}
	}

	return nullptr;

}


