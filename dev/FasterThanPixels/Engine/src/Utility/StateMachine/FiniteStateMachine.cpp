#include "FiniteStateMachine.h"
#include "State.h"

Engine::FiniteStateMachine::FiniteStateMachine()
{
}

void Engine::FiniteStateMachine::Add_States(FSM_State* newstate)
{
	StatesList.push_back(newstate);

}

void Engine::FiniteStateMachine::Reset_FSM()
{
	Current_States = Initial_States;
	Current_States->Begin_Play();
	Continued = true;
	Run_FSM(false);
}

void Engine::FiniteStateMachine::Transit_To(FSM_State* nextstate)
{
	Current_States->End_Play();
	Current_States = nextstate;
	Current_States->Begin_Play();
}

void Engine::FiniteStateMachine::Run_FSM(bool reset)
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

void Engine::FiniteStateMachine::Stop_FSM()
{
	Current_States->End_Play();
}

Engine::FSM_State* Engine::FiniteStateMachine::FindByName(std::string name)
{
	for (FSM_State* state : StatesList)
	{
		if (state->param.StateName == name) {
			return state;
		}
	}

	return nullptr;
}
