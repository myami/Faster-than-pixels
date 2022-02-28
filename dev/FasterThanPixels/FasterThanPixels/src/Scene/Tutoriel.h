#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class Tutoriel
* \brief classe enfant de Scene, represente la scene qui a toutes les infos du jeu(compendium)
*
*/
class Tutoriel : public Engine::Scene {
public:
	Tutoriel(std::string name, FTP_SceneManager* refs);
	FTP_SceneManager* _SceneManager;
	void S_Syteme(); // tout les systeme de la scene ( tout les system lie au component)
	void S_Update(); // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render(); // fin de frame affiche le resultat de la simulation 4/4
	void S_Action(); // Input recu 2/4 quand le joueur presse sur X le gamemanager va checker si dans ActionScene il y a une action sur se input et si oui lance l'action ici 
	void S_Simulation(); // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
	void S_ActionTrigger(std::string ActionName);
	void S_Begin_Play();
	void S_End_Scene();

};