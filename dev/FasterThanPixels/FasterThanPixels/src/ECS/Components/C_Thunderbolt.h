#pragma once
#include "Engine.h"
/*! \class C_Thunderbolt
* \brief classe representant le component Thunderbolt, Si l'entite a ce component, cela veux dire que il peux tirer plus vite pendant une certaines duree
*
*/
class C_Thunderbolt : public Engine::BlankComponent {
public:
	int Amount; /*!< nombre dans l inventaire */
	int MaxAmount; /*!< maximum dans l inventaire */
	float Duration; /*!< Duree du bonus */
};