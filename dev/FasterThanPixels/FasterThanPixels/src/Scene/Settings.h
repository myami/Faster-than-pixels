#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class Option
* \brief classe enfant de Scene, represente le menu d option du jeu
*
*/
class Settings : public Engine::BlankScene {
public:
	Settings(std::string name, FTP_SceneManager* refs);
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_Begin_Play() override;
	void S_End_Scene() override;
	void S_Input_Mouse(sf::Event event) override;


};