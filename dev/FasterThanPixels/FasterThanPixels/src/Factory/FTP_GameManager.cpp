#include "FTP_GameManager.h"
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "FTP_SceneManager.h"

void FTP_GameManager::Game_Init()
{
	Windows = new sf::RenderWindow (sf::VideoMode(1020,1080), "Faster Than Pixels");
    G_SceneManager = std::unique_ptr<FTP_SceneManager>(new FTP_SceneManager());
    G_SceneManager->Init();
    CurrentScene = "Cinematique";
    Engine::LoadAssetFromFile();
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
    }
    G_SceneManager->GetCurrentScene(CurrentScene).S_Action();
}
