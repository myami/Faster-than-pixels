#pragma once
// inventaire
#include "Engine.h"
#include "C_Pickup.h"
/*! \class C_ItemList
* \brief classe representant le component ItemList, Si l'entite l'a cela lui permait d'avoir un inventaire
*
*/
class C_ItemList : public Engine::Component {
	std::map<int, C_Pickup> Inventory;  /*!< Liste d'item de l'entite */
};