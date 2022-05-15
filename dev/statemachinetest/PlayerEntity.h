#pragma once
#include "Entity.h"
class PlayerEntity : public Entity {
public:
	PlayerEntity();
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;
};