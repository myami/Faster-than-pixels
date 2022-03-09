#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class Pause
* \brief classe enfant de Scene, represente le menu de pause pendant le jeu
*
*/
class Pause : public Engine::BlankScene {
public:
	Pause(std::string name, FTP_SceneManager* refs);
	void S_Update() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_ActionTrigger(std::string ActionName) override;
	void S_Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;


};