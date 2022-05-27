#pragma once
#include "Engine.h"
/*! \class Asteroid
* \brief classe representant une entite d'asteroid, qui sont une partie de l'environnement qui est dynamique
*
*/
class Asteroid : public Engine::Entity {
public:
	Asteroid();
	Asteroid(Engine::Scene* sc);
	Asteroid(Engine::Scene* sc, int id);

	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;
};
