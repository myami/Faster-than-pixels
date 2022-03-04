#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class Authentification
* \brief classe enfant de Scene, represente le niveau ou le joueur rentre ces infos pour se connecter au jeu
*
*/
class Authentification : public Engine::Scene {
public:
	Authentification(std::string name, FTP_SceneManager* refs);
	void S_Syteme(); // tout les systeme de la scene ( tout les system lie au component)
	void S_Update(); // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render(); // fin de frame affiche le resultat de la simulation 4/4
	void S_Simulation(); // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
	void S_ActionTrigger(std::string ActionName);
	void S_Begin_Play();
	void S_End_Scene();
	void S_Input_Mouse(sf::Event event);


};