#pragma once
#include "Engine.h"
/*! \class C_Missiles
* \brief classe representant le component Laser, Si l'entite l'a cela lui permait de pouvoir tirer des missiles si il en ramasse
*
*/
class C_Missiles : public Engine::BlankComponent {
public:
	int Amount; /*!< nombre dans l inventaire */
	int MaxAmount; /*!< Maximum dans l inventaire */
};