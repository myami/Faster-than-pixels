#pragma once
#include "Engine.h"
/*! \class C_Punching
* \brief classe representant le component Punching, Si l'entite l'a cela lui permait de pouvoir utiliser le bonus perforation pour une certaines duree
*
*/
class C_Punching : public Engine::Component {
public:
	int Amount; /*!< nombre dans l inventaire */
	int MaxAmount; /*!< maximum dans l inventaire */
	float Duration; /*!< Duree du bonus */
};