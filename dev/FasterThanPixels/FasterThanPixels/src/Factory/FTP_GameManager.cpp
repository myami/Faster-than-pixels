#include "FTP_GameManager.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "FTP_SceneManager.h"
#include "FTP_AssetManager.h"

void FTP_GameManager::Game_Init(std::string NameOfTheGame, std::string FirstScene)
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	Windows = new sf::RenderWindow (sf::VideoMode(desktop.width, desktop.height), NameOfTheGame);
    View.setSize(desktop.width, desktop.height);
    View.setCenter(Windows->getSize().x / 2.f, Windows->getSize().y / 2.f);
    Windows->setView(View);

    G_SceneManager = new FTP_SceneManager(this);
    G_AssetManager = new FTP_AssetManager();
    G_AssetManager->InitAsset();
    G_SceneManager->Init(FirstScene);

    
}


