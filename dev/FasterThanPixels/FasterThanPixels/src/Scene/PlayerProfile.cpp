#include "../Factory/FTP_SceneManager.h"
#include "PlayerProfile.h"

PlayerProfile::PlayerProfile(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
}

void PlayerProfile::S_Render()
{

	_SceneManager->_GameManager->Windows->draw(Background);
	_SceneManager->_GameManager->Windows->draw(Title);
	_SceneManager->_GameManager->Windows->draw(MenuTitle);

	_SceneManager->_GameManager->Windows->draw(Name);
	_SceneManager->_GameManager->Windows->draw(Level);
	_SceneManager->_GameManager->Windows->draw(SwaptoStats.ButtonText);
	_SceneManager->_GameManager->Windows->draw(SwaptoAchievements.ButtonText);
	_SceneManager->_GameManager->Windows->draw(Back.ButtonSprite);


	if (DisplayStats)
	{
		_SceneManager->_GameManager->Windows->draw(Interceptor);
		_SceneManager->_GameManager->Windows->draw(Bomber);
		_SceneManager->_GameManager->Windows->draw(Fighter);
		_SceneManager->_GameManager->Windows->draw(Carrier);
		_SceneManager->_GameManager->Windows->draw(Turret);
		_SceneManager->_GameManager->Windows->draw(Asteroid);
		_SceneManager->_GameManager->Windows->draw(Castaway);
		_SceneManager->_GameManager->Windows->draw(Missions);

	}


}

void PlayerProfile::S_Begin_Play()
{
	DisplayStats = true;

	//TO DO : Récupérer les infos de la DB en fonction du nom de l'utilisateur 

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
	MenuTitle.setString("PLAYER PROFILE");
	MenuTitle.setCharacterSize(32);
	MenuTitle.setFillColor(sf::Color::White);
	MenuTitle.setOrigin(MenuTitle.getGlobalBounds().width / 2.f, MenuTitle.getGlobalBounds().height / 2.f);
	MenuTitle.setPosition(_SceneManager->_GameManager->View.getCenter());
	MenuTitle.move(sf::Vector2(0.f, -325.f));
#pragma endregion

	Name.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Name.setString("PILOT : ");
	Name.setCharacterSize(20);
	Name.setFillColor(sf::Color::White);
	Name.setOrigin(Name.getGlobalBounds().width / 2.f, Name.getGlobalBounds().height / 2.f);
	Name.setPosition(_SceneManager->_GameManager->View.getCenter());
	Name.move(sf::Vector2(-300.f, -220.f));

	Level.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Level.setString("LEVEL : ");
	Level.setCharacterSize(20);
	Level.setFillColor(sf::Color::White);
	Level.setOrigin(Level.getGlobalBounds().width / 2.f, Level.getGlobalBounds().height / 2.f);
	Level.setPosition(_SceneManager->_GameManager->View.getCenter());
	Level.move(sf::Vector2(-300.f, -175.f));

	Interceptor.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Interceptor.setString("INTERCEPTOR DESTROYED : ");
	Interceptor.setCharacterSize(16);
	Interceptor.setFillColor(sf::Color::White);
	Interceptor.setOrigin(Interceptor.getGlobalBounds().width / 2.f, Interceptor.getGlobalBounds().height / 2.f);
	Interceptor.setPosition(_SceneManager->_GameManager->View.getCenter());
	Interceptor.move(sf::Vector2(-300.f, 0.f));

	Bomber.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Bomber.setString("BOMBERS DESTROYED : ");
	Bomber.setCharacterSize(16);
	Bomber.setFillColor(sf::Color::White);
	Bomber.setOrigin(Bomber.getGlobalBounds().width / 2.f, Bomber.getGlobalBounds().height / 2.f);
	Bomber.setPosition(_SceneManager->_GameManager->View.getCenter());
	Bomber.move(sf::Vector2(-300.f, 50.f));

	Fighter.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Fighter.setString("FIGHTER DESTROYED : ");
	Fighter.setCharacterSize(16);
	Fighter.setFillColor(sf::Color::White);
	Fighter.setOrigin(Fighter.getGlobalBounds().width / 2.f, Fighter.getGlobalBounds().height / 2.f);
	Fighter.setPosition(_SceneManager->_GameManager->View.getCenter());
	Fighter.move(sf::Vector2(-300.f, 100.f));

	Carrier.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Carrier.setString("CARRIERS DESTROYED : ");
	Carrier.setCharacterSize(16);
	Carrier.setFillColor(sf::Color::White);
	Carrier.setOrigin(Carrier.getGlobalBounds().width / 2.f, Carrier.getGlobalBounds().height / 2.f);
	Carrier.setPosition(_SceneManager->_GameManager->View.getCenter());
	Carrier.move(sf::Vector2(-300.f, 150.f));

	Turret.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Turret.setString("TURRETS DESTROYED : ");
	Turret.setCharacterSize(16);
	Turret.setFillColor(sf::Color::White);
	Turret.setOrigin(Turret.getGlobalBounds().width / 2.f, Turret.getGlobalBounds().height / 2.f);
	Turret.setPosition(_SceneManager->_GameManager->View.getCenter());
	Turret.move(sf::Vector2(300.f, 0.f));

	Asteroid.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Asteroid.setString("ASTEROIDS DESTROYED : ");
	Asteroid.setCharacterSize(16);
	Asteroid.setFillColor(sf::Color::White);
	Asteroid.setOrigin(Asteroid.getGlobalBounds().width / 2.f, Asteroid.getGlobalBounds().height / 2.f);
	Asteroid.setPosition(_SceneManager->_GameManager->View.getCenter());
	Asteroid.move(sf::Vector2(300.f, 50.f));

	Castaway.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Castaway.setString("CASTAWAY SAVED : ");
	Castaway.setCharacterSize(16);
	Castaway.setFillColor(sf::Color::White);
	Castaway.setOrigin(Castaway.getGlobalBounds().width / 2.f, Castaway.getGlobalBounds().height / 2.f);
	Castaway.setPosition(_SceneManager->_GameManager->View.getCenter());
	Castaway.move(sf::Vector2(300.f, 100.f));

	Missions.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	Missions.setString("MISSION COMPLETED : ");
	Missions.setCharacterSize(16);
	Missions.setFillColor(sf::Color::White);
	Missions.setOrigin(Missions.getGlobalBounds().width / 2.f, Missions.getGlobalBounds().height / 2.f);
	Missions.setPosition(_SceneManager->_GameManager->View.getCenter());
	Missions.move(sf::Vector2(300.f, 150.f));

	SwaptoStats.InitButton("Statistics", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x - 150.f, _SceneManager->_GameManager->View.getCenter().y - 100.f),
		_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20);

	SwaptoAchievements.InitButton("Achievements", sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x + 150.f, _SceneManager->_GameManager->View.getCenter().y - 100.f),
		_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20);

	SwaptoStats.ButtonText.setFillColor(sf::Color::Cyan);
	SwaptoAchievements.ButtonText.setFillColor(sf::Color::White);

	Back.InitButton(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackButton"), sf::Vector2f(_SceneManager->_GameManager->View.getCenter().x, _SceneManager->_GameManager->View.getCenter().y + 400.f));

}

void PlayerProfile::S_Update() 
{

}

void PlayerProfile::S_Input_Mouse(sf::Event event)
{
	if (SwaptoAchievements.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (DisplayStats)
		{
			DisplayStats = false;
			SwaptoStats.ButtonText.setFillColor(sf::Color::White);
			SwaptoAchievements.ButtonText.setFillColor(sf::Color::Cyan);
		}
	}
	if (SwaptoStats.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		if (!DisplayStats)
		{
			DisplayStats = true;
			SwaptoStats.ButtonText.setFillColor(sf::Color::Cyan);
			SwaptoAchievements.ButtonText.setFillColor(sf::Color::White);
		}
	}
	if (Back.IsSpriteClicked(_SceneManager->_GameManager->Windows)) {
		std::cout << "Back";
		_SceneManager->ChangeScene("MainMenu");
	}

}
