#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class PlayerProfile
* \brief classe enfant de Scene, represente le menu ou le joueur peux voir ces stat globales
*
*/
class PlayerProfile : public Engine::BlankScene {
public:
	PlayerProfile(std::string name, FTP_SceneManager* refs);
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_Begin_Play() override;
	void S_End_Scene() override;
	void S_Input_Mouse(sf::Event event) override;



};