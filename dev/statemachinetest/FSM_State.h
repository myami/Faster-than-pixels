#pragma once
#include <string>
struct FSM_Param {
	bool isterminal;
	std::string NextScene;
	bool StopState;
	std::string StateName;
};
class FSM_State
{
public:
	virtual void Begin_Play() = 0;
	virtual void Tick() = 0;
	virtual void End_Play() = 0;
	FSM_Param param;


};

