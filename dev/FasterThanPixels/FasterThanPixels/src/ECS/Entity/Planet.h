#pragma once
#include "Engine.h"
/*! \class Enemie
* \brief classe parent de tout les enemies
*
*/
class Planet : public Engine::Entity {
public:
	Planet();
	Planet(Engine::Scene* sc);
	Planet(Engine::Scene* sc, int id);

	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;
};
