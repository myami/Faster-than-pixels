#include "Settings.h"
#include "../Factory/FTP_SceneManager.h"
#include <iostream>

Settings::Settings(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
}

void Settings::S_Render()
{
	_SceneManager->_GameManager->Windows->draw(Background);
	_SceneManager->_GameManager->Windows->draw(Title);
	_SceneManager->_GameManager->Windows->draw(MenuTitle);

	_SceneManager->_GameManager->Windows->draw(Resolution);
	_SceneManager->_GameManager->Windows->draw(PrevResButton.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(ResolutionValue);
	_SceneManager->_GameManager->Windows->draw(NextResButton.ButtonSprite);

	_SceneManager->_GameManager->Windows->draw(FullScreen);
	_SceneManager->_GameManager->Windows->draw(FullScreenBox.CheckBoxSprite);
	if (FullScreenBox.State == true)
	{
		_SceneManager->_GameManager->Windows->draw(FullScreenBox.CheckSprite);
	}

	_SceneManager->_GameManager->Windows->draw(MainVolume);
	_SceneManager->_GameManager->Windows->draw(PrevMainVolButton.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(MainVolumeValue);
	_SceneManager->_GameManager->Windows->draw(NextMainVolButton.ButtonSprite);

	_SceneManager->_GameManager->Windows->draw(MusicVolume);
	_SceneManager->_GameManager->Windows->draw(PrevMusicVolButton.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(MusicVolumeValue);
	_SceneManager->_GameManager->Windows->draw(NextMusicVolButton.ButtonSprite);

	_SceneManager->_GameManager->Windows->draw(SoundVolume);
	_SceneManager->_GameManager->Windows->draw(PrevSoundVolButton.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(SoundVolumeValue);
	_SceneManager->_GameManager->Windows->draw(NextSoundVolButton.ButtonSprite);

	_SceneManager->_GameManager->Windows->draw(Apply.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Back.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Info);
}

void Settings::S_ActionTrigger(std::string ActionName)
{
}

void Settings::Begin_Play()
{
#pragma region Initialisation_Params

	if (Engine::FileExists("./settings.json"))
	{
		SettingsParam = Engine::GetInfoFromJSON("./settings.json");

		tmpMainVolumeParam = SettingsParam["MainVolume"];
		tmpMusicVolumeParam = SettingsParam["MusicVolume"];
		tmpSoundVolumeParam = SettingsParam["SoundVolume"];
		tmpResolutionIndex = SettingsParam["Resolution"];
		tmpFullScreenParam = SettingsParam["FullScreen"];
		ScreenSize = ScreenSizes[SettingsParam["Resolution"]];
	}
	else
	{
		ScreenSize = sf::VideoMode::getDesktopMode();
		for (size_t i = 0; i < ScreenSizes.size(); i++)
		{
			if (ScreenSizes[i] == ScreenSize)
				ResolutionIndex = i;
		}

		FullScreenParam = 1;
		MainVolumeParam = 100;
		MusicVolumeParam = 100;
		SoundVolumeParam = 100;

		SettingsParam["Resolution"] = ResolutionIndex;
		SettingsParam["FullScreen"] = FullScreenParam;
		SettingsParam["MainVolume"] = MainVolumeParam;
		SettingsParam["SoundVolume"] = SoundVolumeParam;
		SettingsParam["MusicVolume"] = MusicVolumeParam;

		tmpMainVolumeParam = MainVolumeParam;
		tmpMusicVolumeParam = MusicVolumeParam;
		tmpSoundVolumeParam = SoundVolumeParam;
		tmpResolutionIndex = ResolutionIndex;
		tmpFullScreenParam = FullScreenParam;
		Engine::SerializeData(SettingsParam);
	}

#pragma endregion

#pragma region Background
	Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuBackground"));
	Background.setOrigin(Background.getGlobalBounds().width / 2.f, Background.getGlobalBounds().height / 2.f);
	Background.setPosition(_SceneManager->_GameManager->View.getCenter());
#pragma endregion

#pragma region Title
	Title.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuTitre"));
	Title.setOrigin(Title.getGlobalBounds().width / 2.f, Title.getGlobalBounds().height / 2.f);
	Title.setPosition(_SceneManager->_GameManager->View.getCenter());
	Title.move(sf::Vector2(0.f, -450.f));
#pragma endregion

#pragma region MenuTitleTxt
	MenuTitle.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MenuTitle.setString("SETTINGS");
	MenuTitle.setCharacterSize(32);
	MenuTitle.setFillColor(sf::Color::White);
	MenuTitle.setOrigin(MenuTitle.getGlobalBounds().width / 2.f, MenuTitle.getGlobalBounds().height / 2.f);
	MenuTitle.setPosition(_SceneManager->_GameManager->View.getCenter());
	MenuTitle.move(sf::Vector2(0.f, -325.f));
#pragma endregion

#pragma region Graphics
	Resolution.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Resolution.setString("RESOLUTION");
	Resolution.setCharacterSize(20);
	Resolution.setFillColor(sf::Color::White);
	Resolution.setOrigin(Resolution.getGlobalBounds().width / 2.f, Resolution.getGlobalBounds().height / 2.f);
	Resolution.setPosition(_SceneManager->_GameManager->View.getCenter());
	Resolution.move(sf::Vector2(-300.f, -175.f));

	PrevResButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	PrevResButton.ButtonSprite.setScale(-1, 1);
	PrevResButton.ButtonSprite.move(175.f, -170.f);

	ResolutionValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	ResolutionValue.setString(std::to_string(ScreenSize.width) + "x" + std::to_string(ScreenSize.height));
	ResolutionValue.setCharacterSize(20);
	ResolutionValue.setFillColor(sf::Color::White);
	ResolutionValue.setOrigin(ResolutionValue.getGlobalBounds().width / 2.f, ResolutionValue.getGlobalBounds().height / 2.f);
	ResolutionValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	ResolutionValue.move(sf::Vector2(300.f, -175.f));

	NextResButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	NextResButton.ButtonSprite.move(425.f, -170.f);

	FullScreen.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	FullScreen.setString("FULLSCREEN");
	FullScreen.setCharacterSize(20);
	FullScreen.setFillColor(sf::Color::White);
	FullScreen.setOrigin(FullScreen.getGlobalBounds().width / 2.f, FullScreen.getGlobalBounds().height / 2.f);
	FullScreen.setPosition(_SceneManager->_GameManager->View.getCenter());
	FullScreen.move(sf::Vector2(-300.f, -125.f));

	FullScreenBox.InitCheckBox(_SceneManager->_GameManager->G_AssetManager->GetTexture("CheckBox"), _SceneManager->_GameManager->G_AssetManager->GetTexture("Check"), _SceneManager->_GameManager->View.getCenter(), 0.3, true);
	FullScreenBox.CheckBoxSprite.move(sf::Vector2(300.f, -120.f));
	FullScreenBox.CheckSprite.move(sf::Vector2(300.f, -120.f));

#pragma endregion

#pragma region Audio
	MainVolume.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MainVolume.setString("Main Volume");
	MainVolume.setCharacterSize(20);
	MainVolume.setFillColor(sf::Color::White);
	MainVolume.setOrigin(MainVolume.getGlobalBounds().width / 2.f, MainVolume.getGlobalBounds().height / 2.f);
	MainVolume.setPosition(_SceneManager->_GameManager->View.getCenter());
	MainVolume.move(sf::Vector2(-300.f, -50.f));

	PrevMainVolButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	PrevMainVolButton.ButtonSprite.setScale(-1, 1);
	PrevMainVolButton.ButtonSprite.move(175.f, -50.f);

	MainVolumeValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MainVolumeValue.setString(std::to_string(tmpMainVolumeParam));
	MainVolumeValue.setCharacterSize(20);
	MainVolumeValue.setFillColor(sf::Color::White);
	MainVolumeValue.setOrigin(MainVolumeValue.getGlobalBounds().width / 2.f, MainVolumeValue.getGlobalBounds().height / 2.f);
	MainVolumeValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	MainVolumeValue.move(sf::Vector2(300.f, -50.f));

	NextMainVolButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	NextMainVolButton.ButtonSprite.move(425.f, -50.f);

	MusicVolume.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MusicVolume.setString("Music Volume");
	MusicVolume.setCharacterSize(20);
	MusicVolume.setFillColor(sf::Color::White);
	MusicVolume.setOrigin(MusicVolume.getGlobalBounds().width / 2.f, MusicVolume.getGlobalBounds().height / 2.f);
	MusicVolume.setPosition(_SceneManager->_GameManager->View.getCenter());
	MusicVolume.move(sf::Vector2(-300.f, 0.f));

	PrevMusicVolButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	PrevMusicVolButton.ButtonSprite.setScale(-1, 1);
	PrevMusicVolButton.ButtonSprite.move(175.f, 0.f);

	MusicVolumeValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MusicVolumeValue.setString(std::to_string(tmpMusicVolumeParam));
	MusicVolumeValue.setCharacterSize(20);
	MusicVolumeValue.setFillColor(sf::Color::White);
	MusicVolumeValue.setOrigin(MusicVolumeValue.getGlobalBounds().width / 2.f, MusicVolumeValue.getGlobalBounds().height / 2.f);
	MusicVolumeValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	MusicVolumeValue.move(sf::Vector2(300.f, 0.f));

	NextMusicVolButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	NextMusicVolButton.ButtonSprite.move(425.f, 0.f);

	SoundVolume.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	SoundVolume.setString("Sound Volume");
	SoundVolume.setCharacterSize(20);
	SoundVolume.setFillColor(sf::Color::White);
	SoundVolume.setOrigin(SoundVolume.getGlobalBounds().width / 2.f, SoundVolume.getGlobalBounds().height / 2.f);
	SoundVolume.setPosition(_SceneManager->_GameManager->View.getCenter());
	SoundVolume.move(sf::Vector2(-300.f, 50.f));

	PrevSoundVolButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	PrevSoundVolButton.ButtonSprite.setScale(-1, 1);
	PrevSoundVolButton.ButtonSprite.move(175.f, 50.f);

	SoundVolumeValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	SoundVolumeValue.setString(std::to_string(tmpSoundVolumeParam));
	SoundVolumeValue.setCharacterSize(20);
	SoundVolumeValue.setFillColor(sf::Color::White);
	SoundVolumeValue.setOrigin(SoundVolumeValue.getGlobalBounds().width / 2.f, SoundVolumeValue.getGlobalBounds().height / 2.f);
	SoundVolumeValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	SoundVolumeValue.move(sf::Vector2(300.f, 50.f));

	NextSoundVolButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	NextSoundVolButton.ButtonSprite.move(425.f, 50.f);

#pragma endregion

	Info.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Info.setString("Les changements seront effectifs au prochain démarrage du jeu.");
	Info.setCharacterSize(20);
	Info.setFillColor(sf::Color::White);
	Info.setOrigin(Info.getGlobalBounds().width / 2.f, Info.getGlobalBounds().height / 2.f);
	Info.setPosition(_SceneManager->_GameManager->View.getCenter());
	Info.move(sf::Vector2(0.f, 450.f));

	Apply.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ApplyButton"));
	Apply.ButtonSprite.setOrigin(Apply.ButtonSprite.getGlobalBounds().width / 2.f, Apply.ButtonSprite.getGlobalBounds().height / 2.f);
	Apply.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Apply.ButtonSprite.move(sf::Vector2(-200.f, 400.f));

	Back.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackButton"));
	Back.ButtonSprite.setOrigin(Back.ButtonSprite.getGlobalBounds().width / 2.f, Back.ButtonSprite.getGlobalBounds().height / 2.f);
	Back.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Back.ButtonSprite.move(sf::Vector2(200.f, 400.f));
}

void Settings::Tick()
{
	ResolutionValue.setString(std::to_string(ScreenSize.width) + "x" + std::to_string(ScreenSize.height));
	MainVolumeValue.setString(std::to_string(tmpMainVolumeParam));
	MusicVolumeValue.setString(std::to_string(tmpMusicVolumeParam));
	SoundVolumeValue.setString(std::to_string(tmpSoundVolumeParam));
}

void Settings::S_Input_Mouse(sf::Event event)
{
	if (FullScreenBox.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (FullScreenBox.State == true)
		{
			FullScreenBox.State = false;
			tmpFullScreenParam = 0;
		}
		else
		{
			FullScreenBox.State = true;
			tmpFullScreenParam = 1;
		}
	}
	if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		_SceneManager->ChangeScene("MainMenu");
	}
	if (Apply.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		SettingsParam["Resolution"] = tmpResolutionIndex;
		SettingsParam["FullScreen"] = tmpFullScreenParam;
		SettingsParam["MainVolume"] = tmpMainVolumeParam;
		SettingsParam["SoundVolume"] = tmpSoundVolumeParam;
		SettingsParam["MusicVolume"] = tmpMusicVolumeParam;

		Engine::SerializeData(SettingsParam);
		_SceneManager->ChangeScene("MainMenu");
	}

	if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		_SceneManager->ChangeScene("MainMenu");
	}
	if (PrevResButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpResolutionIndex <= 0)
			tmpResolutionIndex = 0;
		else
			tmpResolutionIndex--;
		ScreenSize = ScreenSizes[tmpResolutionIndex];
	}
	if (NextResButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpResolutionIndex >= ScreenSizes.size() - 1)
			tmpResolutionIndex = ScreenSizes.size() - 1;
		else
			tmpResolutionIndex++;
		ScreenSize = ScreenSizes[tmpResolutionIndex];
	}

	if (PrevSoundVolButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpSoundVolumeParam <= 0)
			tmpSoundVolumeParam = 0;
		else
			tmpSoundVolumeParam -= 10;
	}
	if (NextSoundVolButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpSoundVolumeParam >= 100)
			tmpSoundVolumeParam = 100;
		else
			tmpSoundVolumeParam += 10;
	}
	if (PrevMusicVolButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpMusicVolumeParam <= 0)
			tmpMusicVolumeParam = 0;
		else
			tmpMusicVolumeParam -= 10;
	}
	if (NextMusicVolButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpMusicVolumeParam >= 100)
			tmpMusicVolumeParam = 100;
		else
			tmpMusicVolumeParam += 10;
	}
	if (PrevMainVolButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpMainVolumeParam <= 0)
			tmpMainVolumeParam = 0;
		else
			tmpMainVolumeParam -= 10;
	}
	if (NextMainVolButton.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (tmpMainVolumeParam >= 100)
			tmpMainVolumeParam = 100;
		else
			tmpMainVolumeParam += 10;
	}
}