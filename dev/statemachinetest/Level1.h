#pragma once
#include "Scene.h"
class Level1 : public Scene{
public:
	Level1();
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;
	char input;
};