#pragma once
#include "Scene.h"
class Level0 : public Scene {
public:
	Level0();
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;

	char input;
};