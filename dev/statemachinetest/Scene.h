#pragma once
#include "FSM_State.h"
#include <string>
class Scene : public FSM_State
{
public:
	Scene(std::string name);
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;

};