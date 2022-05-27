#pragma once
#include "Engine.h"

/*! \class Player
* \brief classe representant le joueur
*
*/
class Player : public Engine::Entity {
public:
	Player();
	Player(Engine::Scene* sc);
	Player(Engine::Scene* sc, int id);
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;

	void Input(std::string ActioName);
	void CheckLimit();
	void GetDamage(int amount);
	float viewspeed = 200.f;
	float rotationspeed = 2.f;
};
