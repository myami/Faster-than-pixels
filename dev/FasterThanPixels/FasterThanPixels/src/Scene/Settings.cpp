#include "Settings.h"
#include "../Factory/FTP_SceneManager.h"

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
	_SceneManager->_GameManager->Windows->draw(PrevButton.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(ResolutionValue);
	_SceneManager->_GameManager->Windows->draw(NextButton.ButtonSprite);

	_SceneManager->_GameManager->Windows->draw(FullScreen);
	_SceneManager->_GameManager->Windows->draw(FullScreenBox.CheckBoxSprite);
	if (FullScreenBox.State==true)
	{
		_SceneManager->_GameManager->Windows->draw(FullScreenBox.CheckSprite);
	}

	_SceneManager->_GameManager->Windows->draw(MainVolume);
	_SceneManager->_GameManager->Windows->draw(SliderMain.Background);
	_SceneManager->_GameManager->Windows->draw(SliderMain.SliderBar);
	_SceneManager->_GameManager->Windows->draw(MainVolumeValue);	

	_SceneManager->_GameManager->Windows->draw(MusicVolume);
	_SceneManager->_GameManager->Windows->draw(SliderMusic.Background);
	_SceneManager->_GameManager->Windows->draw(SliderMusic.SliderBar);
	_SceneManager->_GameManager->Windows->draw(MusicVolumeValue);

	_SceneManager->_GameManager->Windows->draw(SoundVolume);
	_SceneManager->_GameManager->Windows->draw(SliderSound.Background);
	_SceneManager->_GameManager->Windows->draw(SliderSound.SliderBar);
	_SceneManager->_GameManager->Windows->draw(SoundVolumeValue);


	_SceneManager->_GameManager->Windows->draw(Apply.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Back.ButtonSprite);







}

void Settings::S_ActionTrigger(std::string ActionName)
{
}


void Settings::S_Begin_Play()
{

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

	PrevButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	PrevButton.ButtonSprite.setScale(-1, 1);
	PrevButton.ButtonSprite.move(175.f, -170.f);

	ResolutionValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	ResolutionValue.setString("PlaceHolder");
	ResolutionValue.setCharacterSize(20);
	ResolutionValue.setFillColor(sf::Color::White);
	ResolutionValue.setOrigin(ResolutionValue.getGlobalBounds().width / 2.f, ResolutionValue.getGlobalBounds().height / 2.f);
	ResolutionValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	ResolutionValue.move(sf::Vector2(300.f, -175.f));

	NextButton.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("Arrow"), _SceneManager->_GameManager->View.getCenter());
	NextButton.ButtonSprite.move(425.f, -170.f);

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

	SliderMain.Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundShield"));
	SliderMain.Background.rotate(90.f);
	SliderMain.Background.setOrigin(SliderMain.Background.getGlobalBounds().width / 2.f, SliderMain.Background.getGlobalBounds().height / 2.f);
	SliderMain.Background.setPosition(_SceneManager->_GameManager->View.getCenter());
	SliderMain.Background.move(sf::Vector2(420.f, 70.f));
	SliderMain.Background.scale(0.5, 0.5);

	SliderMain.SliderBar.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SliderShield"));
	SliderMain.SliderBar.rotate(90.f);
	SliderMain.SliderBar.setOrigin(SliderMain.SliderBar.getGlobalBounds().height / 2.f, SliderMain.SliderBar.getGlobalBounds().width / 2.f);
	SliderMain.SliderBar.setPosition(_SceneManager->_GameManager->View.getCenter());
	SliderMain.SliderBar.move(sf::Vector2(420.f, -45.f));
	SliderMain.SliderBar.scale(0.1, 0.05);
	SliderMain.InitSlider(0, 100, 10, false, 100);

	MainVolumeValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MainVolumeValue.setString(std::to_string(trunc(SliderMain.GetSliderPosition())));
	MainVolumeValue.setCharacterSize(20);
	MainVolumeValue.setFillColor(sf::Color::White);
	MainVolumeValue.setOrigin(MainVolumeValue.getGlobalBounds().width / 2.f, MainVolumeValue.getGlobalBounds().height / 2.f);
	MainVolumeValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	MainVolumeValue.move(sf::Vector2(550.f, -50.f));

	MusicVolume.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MusicVolume.setString("Music Volume");
	MusicVolume.setCharacterSize(20);
	MusicVolume.setFillColor(sf::Color::White);
	MusicVolume.setOrigin(MusicVolume.getGlobalBounds().width / 2.f, MusicVolume.getGlobalBounds().height / 2.f);
	MusicVolume.setPosition(_SceneManager->_GameManager->View.getCenter());
	MusicVolume.move(sf::Vector2(-300.f, 0.f));

	SliderMusic.Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundShield"));
	SliderMusic.Background.rotate(90.f);
	SliderMusic.Background.setOrigin(SliderMusic.Background.getGlobalBounds().width / 2.f, SliderMusic.Background.getGlobalBounds().height / 2.f);
	SliderMusic.Background.setPosition(_SceneManager->_GameManager->View.getCenter());
	SliderMusic.Background.move(sf::Vector2(420.f, 120.f));
	SliderMusic.Background.scale(0.5, 0.5);

	SliderMusic.SliderBar.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SliderShield"));
	SliderMusic.SliderBar.rotate(90.f);
	SliderMusic.SliderBar.setOrigin(SliderMusic.SliderBar.getGlobalBounds().height / 2.f, SliderMusic.SliderBar.getGlobalBounds().width / 2.f);
	SliderMusic.SliderBar.setPosition(_SceneManager->_GameManager->View.getCenter());
	SliderMusic.SliderBar.move(sf::Vector2(420.f, 5.f));
	SliderMusic.SliderBar.scale(0.1, 0.05);
	SliderMusic.InitSlider(0, 100, 10, false, 100);
	
	MusicVolumeValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MusicVolumeValue.setString(std::to_string(trunc(SliderMain.GetSliderPosition())));
	MusicVolumeValue.setCharacterSize(20);
	MusicVolumeValue.setFillColor(sf::Color::White);
	MusicVolumeValue.setOrigin(MusicVolumeValue.getGlobalBounds().width / 2.f, MusicVolumeValue.getGlobalBounds().height / 2.f);
	MusicVolumeValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	MusicVolumeValue.move(sf::Vector2(550.f, 0.f));

	SoundVolume.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	SoundVolume.setString("Sound Volume");
	SoundVolume.setCharacterSize(20);
	SoundVolume.setFillColor(sf::Color::White);
	SoundVolume.setOrigin(SoundVolume.getGlobalBounds().width / 2.f, SoundVolume.getGlobalBounds().height / 2.f);
	SoundVolume.setPosition(_SceneManager->_GameManager->View.getCenter());
	SoundVolume.move(sf::Vector2(-300.f, 50.f));

	SliderSound.Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundShield"));
	SliderSound.Background.rotate(90.f);
	SliderSound.Background.setOrigin(SliderSound.Background.getGlobalBounds().width / 2.f, SliderSound.Background.getGlobalBounds().height / 2.f);
	SliderSound.Background.setPosition(_SceneManager->_GameManager->View.getCenter());
	SliderSound.Background.move(sf::Vector2(420.f, 170.f));
	SliderSound.Background.scale(0.5, 0.5);

	SliderSound.SliderBar.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SliderShield"));
	SliderSound.SliderBar.rotate(90.f);
	SliderSound.SliderBar.setOrigin(SliderSound.SliderBar.getGlobalBounds().height / 2.f, SliderSound.SliderBar.getGlobalBounds().width / 2.f);
	SliderSound.SliderBar.setPosition(_SceneManager->_GameManager->View.getCenter());
	SliderSound.SliderBar.move(sf::Vector2(420.f, 55.f));
	SliderSound.SliderBar.scale(0.1, 0.05);
	SliderSound.InitSlider(0, 100, 10, false, 100);

	SoundVolumeValue.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	SoundVolumeValue.setString(std::to_string(trunc(SliderMain.GetSliderPosition())));
	SoundVolumeValue.setCharacterSize(20);
	SoundVolumeValue.setFillColor(sf::Color::White);
	SoundVolumeValue.setOrigin(SoundVolumeValue.getGlobalBounds().width / 2.f, SoundVolumeValue.getGlobalBounds().height / 2.f);
	SoundVolumeValue.setPosition(_SceneManager->_GameManager->View.getCenter());
	SoundVolumeValue.move(sf::Vector2(550.f, 50.f));
#pragma endregion

	Apply.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ApplyButton"));
	Apply.ButtonSprite.setOrigin(Apply.ButtonSprite.getGlobalBounds().width / 2.f, Apply.ButtonSprite.getGlobalBounds().height / 2.f);
	Apply.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Apply.ButtonSprite.move(sf::Vector2(-200.f, 400.f));

	Back.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackButton"));
	Back.ButtonSprite.setOrigin(Back.ButtonSprite.getGlobalBounds().width / 2.f, Back.ButtonSprite.getGlobalBounds().height / 2.f);
	Back.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Back.ButtonSprite.move(sf::Vector2(200.f, 400.f));
}



void Settings::S_Input_Mouse(sf::Event event)
{
	if (FullScreenBox.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if(FullScreenBox.State == true)
			FullScreenBox.State = false;
		else
			FullScreenBox.State = true;
	}
	if (SliderSound.SlideBar.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {}
	if (SliderMusic.SliderBar.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {}
	if (SliderMain.SliderBar.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {}
	if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {}
	if (Apply.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		//Creation / Modification du fichier Setting
		std::cout << "Applied Changes";
		_SceneManager->ChangeScene("MainMenu");
	}
	
	if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		std::cout << "Back";
		_SceneManager->ChangeScene("MainMenu");
	}

}


