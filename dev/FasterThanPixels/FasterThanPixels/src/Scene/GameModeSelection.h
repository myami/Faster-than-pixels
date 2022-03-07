#pragma once

#include "Engine.h"
class FTP_SceneManager;
/*! \class MainMenu
* \brief classe enfant de Scene, represente le menu principale du jeu
*
*/
class GameModeSelection : public Engine::Scene {
public:
	GameModeSelection(std::string name, FTP_SceneManager* refs);
	void S_Syteme(); // tout les systeme de la scene ( tout les system lie au component)
	void S_Update(); // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render(); // fin de frame affiche le resultat de la simulation 4/4
	void S_Simulation(); // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
	void S_ActionTrigger(std::string ActionName);
	void S_Begin_Play();
	void S_End_Scene();
	void S_Input_Mouse(sf::Event event);
	void S_Input_Text(sf::Event event);

	sf::Sprite Background;  /*!< Sprite du background */
	sf::Sprite Title; /*!< Sprite du titre du jeu */

	sf::RectangleShape Borders; /*!< Debug only */

	sf::Text MenuTitle;
	Button Easy;  /*!< bouton Play, modifie la difficulte pour facile */
	Button Medium;  /*!< bouton Compendium, modifie la difficulte pour moyen */
	Button Hard;  /*!< bouton Profile, modifie la difficulte pour difficile*/
	Button Training;  /*!< bouton Training, modifie le mode de jeu pour Training*/
	Button FastAction;  /*!< bouton Profile,  modifie le mode de jeu pour Action Rapide*/
	Button Multiplayer;  /*!< bouton Profile, envoie vers la scene PlayerProfile*/
	Button StartGame;  /*!< bouton PLAY, envoie vers la scene Game */
	Button Back;/*!< bouton register, appelle la fonction Quit() */


	sf::Sprite ButtonBackground;  /*!< Sprite du background des boutons */
	Input Seed;  /*!< input de la seed pour la generation de la carte, valeur random si vide*/

};

