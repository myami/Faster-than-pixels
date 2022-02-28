#pragma once
#include "Engine.h"
/*! \class C_Shoot
* \brief classe representant le component Shoot, Si l'entite a ce component, cela veux dire que il peux tirer
*
*/
class C_Shoot : public Engine::Component {
	bool canshoot; /*!< Si l'entite peux tirer ou si on lui bloque comme par exemple si il est trop endommager */
};