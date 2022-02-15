#pragma once
// cinematique
#include "Engine.h"
class Starting : public Engine::Scene {

	 void S_Syteme(); // tout les systeme de la scene ( tout les system lie au component)
	 void S_Update(); // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	 void S_Render(); // fin de frame affiche le resultat de la simulation 4/4
	 void S_Action(); // Input recu 2/4
	 void S_Simulation() ; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
	 void S_Action(Engine::Action& action); // quand le joueur presse sur X le gamemanager va checker si dans ActionScene il y a une action sur se input et si oui lance l'action ici 


};