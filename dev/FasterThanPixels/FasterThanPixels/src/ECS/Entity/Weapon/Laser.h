#pragma once
#include "Engine.h"
/*! \class Laser
* \brief classe representant une entite de laser, quand le joueur tire avec, celle-ci apparait en jeu et permait de plus savoir se qu elle rencontre en collision
*
*/
class Laser : public Engine::Entity {
public:
	Laser();
	Laser(Engine::Scene* sc);
	void Begin_Play() override;
	void Tick() override;
	void End_Play() override;

};
