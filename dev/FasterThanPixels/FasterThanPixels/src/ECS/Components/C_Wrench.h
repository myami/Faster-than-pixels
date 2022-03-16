#pragma once
#include "Engine.h"
/*! \class C_Wrench
* \brief classe representant le component Wrench, Si l'entite l'a cela lui permait de pouvoir utiliser le bonus de reparation
*
*/
class C_Wrench : public Engine::BlankComponent {
public:
	int Amount; /*!< nombre dans l inventaire */
	int MaxAmount; /*!< maximum dans l inventaire */
	float RepairAmount; /*!< Nombre de point de vie recuperer */
};