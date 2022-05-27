#pragma once
#include "Engine.h"
/*! \class S_Health
* \brief classe systeme pour le component Health, il permait de changer la vie a des entite et checker si il sont mort
*
*/
class S_Health : public Engine::System {
public:
	void DoDamage(int amount, Engine::Entity* target);
	int GetHealth(Engine::Entity* target);
	void Repair(int amout, Engine::Entity* target);
	bool IsAlive(Engine::Entity* target);
	void RunSystem(float dt) override;
	S_Health();
};
