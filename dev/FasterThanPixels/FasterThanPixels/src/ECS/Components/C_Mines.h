#pragma once
#include "Engine.h"
/*! \class C_Mines
* \brief classe representant le component Mines, Si l'entite l'a cela lui permait de pouvoir poser des mines si il en ramasse
*
*/
class C_Mines : public Engine::Component {
	int Amount;  /*!< nombre dans l inventaire */
	int MaxAmount;  /*!< Maximum qu il peux avoir */
};