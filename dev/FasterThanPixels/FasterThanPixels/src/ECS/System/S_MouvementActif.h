#pragma once
#include "Engine.h"

/*! \class S_Mouvement_Actif
* \brief classe systeme pour le component Mouvement_Actif, Une fois le vector de direction recalculer il change deplace sont entite au bonne endroit
*
*/
class S_Mouvement_Actif : public Engine::System {
public:
	S_Mouvement_Actif();
	void RunSystem(Engine::Entity* Entity, float dt) override;

};
