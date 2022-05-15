#pragma once
#include "FSM_State.h"
#include <string>
#include <map>

class Entity :public FSM_State {
public:
	Entity(std::string name);
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;
	std::string EntityName;
	std::map<std::string, int> Component;
	int ID_entity;

};