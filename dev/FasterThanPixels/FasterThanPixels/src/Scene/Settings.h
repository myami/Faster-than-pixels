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
	void Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void Tick() override;

	const std::vector<sf::VideoMode> ScreenSizes = sf::VideoMode::getFullscreenModes();
	sf::VideoMode ScreenSize;

	int MainVolumeParam;
	int MusicVolumeParam;
	int SoundVolumeParam;
	int ResolutionIndex;
	int FullScreenParam;
	int tmpMainVolumeParam;
	int tmpMusicVolumeParam;
	int tmpSoundVolumeParam;
	int tmpResolutionIndex;
	int tmpFullScreenParam;

	std::map<std::string, int> SettingsParam =
	{
		{"Resolution", ResolutionIndex},
		{"FullScreen", FullScreenParam},
		{"MainVolume", MainVolumeParam},
		{"MusicVolume", MusicVolumeParam},
		{"SoundVolume", SoundVolumeParam},
	};

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
	Button NextMainVolButton;
	Button PrevMainVolButton;

	sf::Text MusicVolume;
	Engine::Slider SliderMusic;
	sf::Text MusicVolumeValue;
	Button NextMusicVolButton;
	Button PrevMusicVolButton;

	sf::Text SoundVolume;
	Engine::Slider SliderSound;
	sf::Text SoundVolumeValue;
	Button NextSoundVolButton;
	Button PrevSoundVolButton;

	sf::Text Info;

	Button NextResButton;
	Button PrevResButton;
	Button Back;
	Button Apply;
};