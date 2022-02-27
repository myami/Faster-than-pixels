#pragma once
#include "Engine.h"
class C_Booster : public Engine::Component {
	float BonusSpeed; // la vitesse a ajouter
	bool AddSpeed; // si on est entrain de la rajouter
};