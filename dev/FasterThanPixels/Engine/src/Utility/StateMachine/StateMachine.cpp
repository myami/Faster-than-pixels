#include "StateMachine.h"
#include "State.h"

Engine::StateMachine::StateMachine()
{
}

void Engine::StateMachine::Add_States(StateParent* newstate) 
{

	StatesList.push_back(newstate);
	newstate->Begin_Play();

}

void Engine::StateMachine::Reset_FSM()
{
	Continued = true;
	Run_FSM(false);
}

void Engine::StateMachine::Run_FSM(bool reset)
{
	if (reset)
		Reset_FSM();
	if (Continued)
	{
		for (StateParent* const& state : StatesList) {
			state->Tick();
		}
		
	}

	if (!Continued) {
		for (StateParent* const& state : StatesList) {
			state->End_Play();
		}
	}

}


