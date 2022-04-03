#include "S_Health.h"
#include "../Components/C_Health.h"

void S_Health::DoDamage(int amount, Engine::Entity* target)
{
	C_Health* Component = (C_Health*)target->GetComponent("Health");
	Component->Health = std::clamp((int)Component->Health - amount, 0, 100);

}

int S_Health::GetHealth(Engine::Entity* target)
{
	C_Health* Component = (C_Health*)target->GetComponent("Health");

	return Component->Health;
}

void S_Health::Repair(int amout, Engine::Entity* target)
{
	C_Health* Component = (C_Health*)target->GetComponent("Health");
	Component->Health =  std::clamp((int)Component->Health + amout, 0, 100);

}

bool S_Health::IsAlive(Engine::Entity* target)
{
	C_Health* Component = (C_Health*)target->GetComponent("Health");
	if (Component->Health == 0)
	{
		return true;
	}

	return false;

}

void S_Health::RunSystem(Engine::Entity* Entity, float dt)
{
	C_Health* Component = (C_Health*)Entity->GetComponent("Health");

	if (Component->Health <= 0) 
	{
		// si joueur alors gameover sinon detruire
		std::cout << "GameOver" << std::endl;

	}
}

S_Health::S_Health()
{
}
