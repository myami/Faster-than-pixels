#include "FTP_GameManager.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "FTP_SceneManager.h"
#include "FTP_AssetManager.h"

void FTP_GameManager::Game_Init(std::string NameOfTheGame, std::string FirstScene)
{
	if (Engine::FileExists("./settings.json"))
		Settings = Engine::GetInfoFromJSON("./settings.json");

	sf::VideoMode desktop = sf::VideoMode::getFullscreenModes()[Settings["Resolution"]];
	if (Settings["FullScreen"])
		Windows = new sf::RenderWindow(sf::VideoMode(desktop.width, desktop.height), NameOfTheGame, sf::Style::Fullscreen);
	else
		Windows = new sf::RenderWindow(sf::VideoMode(desktop.width, desktop.height), NameOfTheGame, sf::Style::Default);
	Windows->setFramerateLimit(30);

	View.setSize(desktop.width, desktop.height);
	View.setCenter(Windows->getSize().x / 2.f, Windows->getSize().y / 2.f);
	Windows->setView(View);

	G_SceneManager = new FTP_SceneManager(this);
	G_AssetManager = new FTP_AssetManager();
	G_AssetManager->InitAsset();
	G_SceneManager->Init(FirstScene);

	Dao->CreateDB();
}

FTP_GameManager::FTP_GameManager() :GameManager()
{
	Engine::DBConnectionInfo db_info;
	db_info.Path = "./DB/";
	Dao = new FTP_DAO(db_info);
}