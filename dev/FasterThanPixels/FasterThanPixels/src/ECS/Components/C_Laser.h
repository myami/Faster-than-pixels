#pragma once
#include "Engine.h"
/*! \class C_Laser
* \brief classe representant le component Laser, Si l'entite l'a cela lui permait de pouvoir tirer des lasers si il en ramasse
*
*/
class C_Laser : public Engine::Component {
	int Amount;  /*!< Nombre que l'entite a actuellement dans sont inventaire */
	int MaxAmount;  /*!< Le maximum qu'il peux avoir */
};