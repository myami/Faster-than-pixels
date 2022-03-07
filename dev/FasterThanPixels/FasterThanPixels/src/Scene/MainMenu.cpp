#include "MainMenu.h"
#include "../Factory/FTP_SceneManager.h"

MainMenu::MainMenu(std::string name, FTP_SceneManager* refs): Engine::Scene(name)
{
	_SceneManager = refs;
}

void MainMenu::S_Syteme()
{
}

void MainMenu::S_Update()
{
}

void MainMenu::S_Render()
{
	_SceneManager->_GameManager->Windows->draw(Background);
	_SceneManager->_GameManager->Windows->draw(Title);
	_SceneManager->_GameManager->Windows->draw(Play.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Compendium.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Profile.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Settings.ButtonSprite);
	_SceneManager->_GameManager->Windows->draw(Exit.ButtonSprite);



}

void MainMenu::S_Simulation()
{
}

void MainMenu::S_ActionTrigger(std::string ActionName)
{
}

void MainMenu::S_Begin_Play()
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

#pragma region PlayBtn
	Play.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("PlayMainMenu"));
	Play.ButtonSprite.setOrigin(Play.ButtonSprite.getGlobalBounds().width / 2.f, Play.ButtonSprite.getGlobalBounds().height / 2.f);
	Play.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Play.ButtonSprite.move(sf::Vector2(-450.f, -10.f));
#pragma endregion

#pragma region CompendiumBtn
	Compendium.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("CompendiumMainMenu"));
	Compendium.ButtonSprite.setOrigin(Compendium.ButtonSprite.getGlobalBounds().width / 2.f, Compendium.ButtonSprite.getGlobalBounds().height / 2.f);
	Compendium.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Compendium.ButtonSprite.move(sf::Vector2(-225.f, -10.f));
#pragma endregion

#pragma region ProfileBtn
	Profile.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ProfileMainMenu"));
	Profile.ButtonSprite.setOrigin(Profile.ButtonSprite.getGlobalBounds().width / 2.f, Profile.ButtonSprite.getGlobalBounds().height / 2.f);
	Profile.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Profile.ButtonSprite.move(sf::Vector2(0.f, -10.f));
#pragma endregion

#pragma region SettingsBtn
	Settings.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SettingsMainMenu"));
	Settings.ButtonSprite.setOrigin(Settings.ButtonSprite.getGlobalBounds().width / 2.f, Settings.ButtonSprite.getGlobalBounds().height / 2.f);
	Settings.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Settings.ButtonSprite.move(sf::Vector2(225.f, -10.f));
#pragma endregion

#pragma region ExitBtn
	Exit.ButtonSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("ExitMainMenu"));
	Exit.ButtonSprite.setOrigin(Exit.ButtonSprite.getGlobalBounds().width / 2.f, Exit.ButtonSprite.getGlobalBounds().height / 2.f);
	Exit.ButtonSprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	Exit.ButtonSprite.move(sf::Vector2(445.f, -10.f));
#pragma endregion
}

void MainMenu::S_End_Scene()
{
}

void MainMenu::S_Input_Mouse(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed) {

		if (Play.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "GMS";
			_SceneManager->ChangeScene("GameModeSelection");
		}
		if (Compendium.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Compendium";
			_SceneManager->ChangeScene("Compendium");
		}
		if (Profile.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Profile";
			_SceneManager->ChangeScene("Profile");
		}
		if (Settings.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Settings";
			_SceneManager->ChangeScene("Settings");
		}
		if (Exit.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
			std::cout << "Byebye";
			_SceneManager->_GameManager->Quit();
		}

	}

}

void MainMenu::S_Input_Text(sf::Event event)
{
}
