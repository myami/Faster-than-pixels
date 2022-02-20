#include "FTP_GameManager.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "FTP_SceneManager.h"
#include "FTP_AssetManager.h"

void FTP_GameManager::Game_Init()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	Windows = new sf::RenderWindow (sf::VideoMode(desktop.width, desktop.height), "Faster Than Pixels");
    View.setSize(desktop.width, desktop.height);
    Windows->setView(View);

    G_SceneManager = std::unique_ptr<FTP_SceneManager>(new FTP_SceneManager(this));
    G_AssetManager = std::unique_ptr<FTP_AssetManager>(new FTP_AssetManager());
    G_SceneManager->Init();
    CurrentScene = "Cinematique";
    G_AssetManager->InitAsset();
    
}

void FTP_GameManager::GameLoop()
{

    while (Windows->isOpen())
    {
        G_SceneManager->GetCurrentScene(CurrentScene).S_Update();
        S_Input();
        G_SceneManager->GetCurrentScene(CurrentScene).S_Simulation();
        G_SceneManager->GetCurrentScene(CurrentScene).S_Syteme();
        Windows->clear();
        G_SceneManager->GetCurrentScene(CurrentScene).S_Render();
        Windows->display();
    }
}

void FTP_GameManager::Quit()
{
    Windows->close();

}

void FTP_GameManager::S_Input()
{
    sf::Event event;
    while (Windows->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Quit();
        else if (event.type == sf::Event::Resized) {
            ResizeView(event);
        }
    }
    G_SceneManager->GetCurrentScene(CurrentScene).S_Action();
}
