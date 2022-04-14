#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class Authentification
* \brief classe enfant de Scene, represente le niveau ou le joueur rentre ces infos pour se connecter au jeu
*
*/
class Authentification : public Engine::BlankScene {
public:
	Authentification(std::string name, FTP_SceneManager* refs);
	void S_Update() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;
	void ShowLogin();
	void ShowRegister();

	bool inscription;
	sf::Sprite Background;  /*!< Sprite du background */
	Button Login;  /*!< bouton login */
	Button Register;  /*!< bouton register */
	Button Back;
	Button Apply;
	sf::Sprite ButtonBackground;  /*!< Sprite du background des boutons */
	sf::Sprite Title;  /*!< Sprite du titre */
	Input UserName;  /*!< input du username */
	Input PassWord;  /*!< input du mot de passe */
	Input Mail;
	Input VerifPassWord;

};