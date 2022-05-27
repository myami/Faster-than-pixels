#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class EndGame
* \brief classe enfant de Scene, represente le niveau ou le joueur vois les infos de fin de partie
*
*/
class EndGame : public Engine::BlankScene {
public:
	EndGame(std::string name, FTP_SceneManager* refs);

	void Tick() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_ActionTrigger(std::string ActionName) override;
	void Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;
};