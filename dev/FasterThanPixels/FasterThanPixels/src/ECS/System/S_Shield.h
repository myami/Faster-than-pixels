#pragma once
#include "Engine.h"
/*! \class S_Shield
* \brief classe systeme pour le component Shied, il permait de gerer les shields des entites
*/
class S_Shield : public Engine::System {
	void RegenerateShield(Engine::Entity* target);
public:
	S_Shield();
	bool AsShield(Engine::Entity* target);
	void RunSystem(float dt) override;
	void DamageShield(int amount, Engine::Entity* target);
	int GetShield(Engine::Entity* target);
};
