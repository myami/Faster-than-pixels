#pragma once
#include "../Utility/GUI/CompendiumInfo.h"
#include "Engine.h"
class FTP_SceneManager;
/*! \class Option
* \brief classe enfant de Scene, represente le menu d option du jeu
*
*/
enum class FirstState { Empty = 0, Ennemis = 1, Bonus = 2, Objectifs = 3 };/*!< Permet d'identifier l'arborescence sélectionnée */
enum class SecondState { Empty = 0, First = 1, Second = 2, Third = 3, Fourth = 4, Fifth = 5 };

class Compendium : public Engine::BlankScene {
public:
	Compendium(std::string name, FTP_SceneManager* refs);
	void S_Render() override;
	void S_ActionTrigger(std::string ActionName) override;
	void Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;
	void Tick() override;

	FirstState FS;
	SecondState SS;

	std::string Status;
	sf::Sprite Background;  /*!< Sprite du background */
	sf::Sprite Title; /*!< Sprite du titre du jeu */
	sf::Sprite CompendiumBg;

	sf::Text MenuTitle;

	Button Ennemis;
	Button Inter;
	CompendiumInfo ci_Inter;
	Button Bomber;
	CompendiumInfo ci_Bomber;
	Button Chasseur;
	CompendiumInfo ci_Chasseur;
	Button Carrier;
	CompendiumInfo ci_Carrier;
	Button Tour;
	CompendiumInfo ci_Tour;

	Button Bonus;
	Button Mines;
	CompendiumInfo ci_Mines;
	Button Reparations;
	CompendiumInfo ci_Reparations;
	Button Missiles;
	CompendiumInfo ci_Missiles;
	Button Surcadencage;
	CompendiumInfo ci_Surcadencage;
	Button Perforation;
	CompendiumInfo ci_Perforation;

	Button Objectifs;
	Button ElimVIP;
	CompendiumInfo ci_ElimVIP;
	Button DernierSurvivant;
	CompendiumInfo ci_DernierSurvivant;
	Button DefenseZone;
	CompendiumInfo ci_DefenseZone;
	Button AssautZone;
	CompendiumInfo ci_AssautZone;
	Button Sauvetage;
	CompendiumInfo ci_Sauvetage;

	Button Back;
};
