#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class Loading
* \brief classe enfant de Scene, represente un menu de chargement
*
*/
class Loading : public Engine::BlankScene {
public:
	Loading(std::string name, FTP_SceneManager* refs);
	
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_ActionTrigger(std::string ActionName) override;
	void Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;


};