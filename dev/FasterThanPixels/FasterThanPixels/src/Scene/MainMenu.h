#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class MainMenu
* \brief classe enfant de Scene, represente le menu principale du jeu
*
*/
class MainMenu : public Engine::BlankScene {
public:
	MainMenu(std::string name, FTP_SceneManager* refs);

	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_Begin_Play() override;
	void S_End_Scene() override;
	void S_Input_Mouse(sf::Event event) override;
		
	sf::Sprite Background;  /*!< Sprite du background */
	sf::Sprite Title; /*!< Sprite du titre du jeu */
	Button Play;  /*!< bouton Play, envoie vers la scene Starting */
	Button Compendium;  /*!< bouton Compendium, envoie vers la scene Compendium */
	Button Profile;  /*!< bouton Profile, envoie vers la scene PlayerProfile*/
	Button Settings;  /*!< bouton Settings, envoie vers la scene Option */
	Button Exit;  /*!< bouton register, appelle la fonction Quit() */
};