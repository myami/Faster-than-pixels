#pragma once
#include "Engine.h"
/*! \class C_Shield
* \brief classe representant le component Shield, Si l'entite a ce component, cela veux dire que il a un bouclier
*
*/
class C_Shield : public Engine::BlankComponent {
public:
	int HealthShield; /*!< Vie du bouclier */
	float RegenerationSpeed; /*!< Vitesse de regeneration */
	float RegenerationAmountPerTick; /*!< Regeneration par tick */
	sf::Clock ShieldClock;/*!< Timer du shield lie a l entite */
	C_Shield();
};