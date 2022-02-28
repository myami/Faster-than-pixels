#pragma once
// barre de vie
#include "Engine.h"
/*! \class C_Health
* \brief classe representant le component Health, Si l'entite l'a cela lui permait d'avoir une barre de vie et de mourrir
*
*/
class C_Health : public Engine::Component {
	float Health;  /*!< Vie de l'entite */
};