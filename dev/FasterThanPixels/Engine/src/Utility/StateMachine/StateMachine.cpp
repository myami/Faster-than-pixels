/*#include "StateMachine.h"

void Engine::StateMachine_Master::SetState(StateMachine_State* NextState)
{
	CurrentState->End_Play();
	CurrentState = NextState;
	CurrentState->Begin_Play();
}

Engine::StateMachine_State* Engine::StateMachine_Master::GetCurrentState()
{
	return CurrentState;
}

void Engine::StateMachine_Master::OnTick()
{
	CurrentState->On_Tick();
}*/
