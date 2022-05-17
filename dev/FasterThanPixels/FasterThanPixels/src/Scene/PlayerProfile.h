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
	void Begin_Play() override;
	void Tick() override;
	void S_Input_Mouse(sf::Event event) override;


	sf::Sprite Background;  /*!< Sprite du background */
	sf::Sprite Title; /*!< Sprite du titre du jeu */

	bool DisplayStats;
	sf::Text MenuTitle;
	sf::Text Name, Level, Interceptor, Bomber, Fighter, Carrier, Turret, Asteroid, Castaway, Missions;

	Button Back,SwaptoStats, SwaptoAchievements;
};