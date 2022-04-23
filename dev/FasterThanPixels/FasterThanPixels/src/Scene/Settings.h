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
	void S_Render() override;
	void S_ActionTrigger(std::string ActionName) override;
	void S_Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;


	sf::Sprite Background;  /*!< Sprite du background */
	sf::Sprite Title; /*!< Sprite du titre du jeu */

	sf::Text MenuTitle;

	sf::Text Resolution;
	sf::Text ResolutionValue;
	sf::Text FullScreen;
	CheckBox FullScreenBox;

	sf::Text MainVolume;
	Engine::Slider SliderMain;
	sf::Text MainVolumeValue;

	sf::Text MusicVolume;
	Engine::Slider SliderMusic;
	sf::Text MusicVolumeValue;

	sf::Text SoundVolume;
	Engine::Slider SliderSound;
	sf::Text SoundVolumeValue;

	Button NextButton;
	Button PrevButton;
	Button Back;
	Button Apply;

	

};