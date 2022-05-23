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
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;

	void Input(std::string ActioName);
	void CheckLimit();

};
