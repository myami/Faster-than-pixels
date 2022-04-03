#include "S_Shield.h"
#include "../Components/C_Shield.h"

void S_Shield::RegenerateShield(Engine::Entity* target)
{
	C_Shield* Component = (C_Shield*)target->GetComponent("Shield");
	Component->HealthShield += Component->RegenerationAmountPerTick;

}

bool S_Shield::AsShield(Engine::Entity* target)
{
	C_Shield* Component = (C_Shield*)target->GetComponent("Shield");
	if (Component->HealthShield > 0) {
		return true;
	}
	else {
		return false;
	}
}

void S_Shield::RunSystem(Engine::Entity* Entity, float dt)
{
	C_Shield* Component = (C_Shield*)Entity->GetComponent("Shield");
	if (Component->ShieldClock.getElapsedTime().asMilliseconds() >= Component->RegenerationSpeed) 
	{
		RegenerateShield(Entity);
		Component->ShieldClock.restart();
	}

}

void S_Shield::DamageShield(int amount, Engine::Entity* target)
{
	C_Shield* Component = (C_Shield*)target->GetComponent("Shield");
	Component->HealthShield -= amount;

}

int S_Shield::GetShield(Engine::Entity* target)
{
	C_Shield* Component = (C_Shield*)target->GetComponent("Shield");

	return Component->HealthShield;
}

S_Shield::S_Shield()
{
}
