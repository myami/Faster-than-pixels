/*#pragma once
namespace Engine {
	class StateMachine_Master 
	{
	public:
		void SetState(StateMachine_State* NextState);
		StateMachine_State* GetCurrentState();
		void OnTick();
	private:
		StateMachine_State* CurrentState;

	};

	class StateMachine_State 
	{
	public:
		virtual void Begin_Play() = 0;
		virtual void On_Tick() = 0;
		virtual void End_Play() = 0;
	};


}*/