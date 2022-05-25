#include "S_Health.h"
#include "../Components/C_Health.h"

void S_Health::DoDamage(int amount, Engine::Entity* target)
{
	if (IsEntityInSystem(target)) 
	{
		C_Health* Component = (C_Health*)target->GetComponent("Health");
		Component->Health = std::clamp((int)Component->Health - amount, 0, 100);
	}


}

int S_Health::GetHealth(Engine::Entity* target)
{
	if (IsEntityInSystem(target))
	{
		C_Health* Component = (C_Health*)target->GetComponent("Health");
		return Component->Health;
	}
	return 0;
}

void S_Health::Repair(int amout, Engine::Entity* target)
{
	if (IsEntityInSystem(target)) {
		C_Health* Component = (C_Health*)target->GetComponent("Health");
		Component->Health = std::clamp((int)Component->Health + amout, 0, 100);
	}


}

bool S_Health::IsAlive(Engine::Entity* target)
{
	if (IsEntityInSystem(target)) {
		C_Health* Component = (C_Health*)target->GetComponent("Health");
		if (Component->Health == 0)
		{
			return true;
		}
	}
	return false;
}

void S_Health::RunSystem(float dt)
{
	for (auto const& Entity : EntityLoop) {

		C_Health* Component = (C_Health*)Entity->GetComponent("Health");

		if (IsAlive(Entity))
		{
			std::cout << "S_Health : Entite : " << Entity->E_Id <<" n'a plus de vie" << std::endl;
		}
	}

}

S_Health::S_Health()
{
}
