#pragma once

#include "Engine.h"


class FTP_SceneManager;
/*! \class Game
* \brief classe enfant de Scene, represente le niveau ou le joueur joue
*
*/
class Game : public Engine::BlankScene {
public:
	Game(std::string name, FTP_SceneManager* refs);
	void S_Syteme() override; // tout les systeme de la scene ( tout les system lie au component)
	void S_Update() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_Simulation() override; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
	void S_ActionTrigger(std::string ActionName) override;
	void S_Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;


	sf::RectangleShape shape;


	float viewspeed = 150.f;

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;
	sf::Text text;

	void InitPlanet();
	void InitAsteroid();

	std::vector<std::string> AvailablePlanet;
	std::vector<std::string> AvailableAsteroid;


};