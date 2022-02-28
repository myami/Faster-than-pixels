#pragma once
#include "Engine.h"
/*! \class C_Booster
* \brief classe representant le component Booster, Si l'entite l'a est quand il peux l utiliser et de combien sa ajoute a la vitesse de base
*
*/
class C_Booster : public Engine::Component {
	float BonusSpeed;  /*!< Vitesse a ajouter */
	bool AddSpeed; //  /*!< Si on est entrain de l'ajouter */
	float TimeToGetIt;  /*!< La duree pour que le boost sois disponible */
	float CurrentTime;  /*!< La duree actuelle entre chaque boost */
};