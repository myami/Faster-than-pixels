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
    Windows->setView(View);

    G_SceneManager = std::unique_ptr<FTP_SceneManager>(new FTP_SceneManager(this));
    G_AssetManager = std::unique_ptr<FTP_AssetManager>(new FTP_AssetManager());
    G_SceneManager->Init(FirstScene);
    G_AssetManager->InitAsset();
    
}


