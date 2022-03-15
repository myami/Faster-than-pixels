#include "GameManager.h"
#include "AssetManager.h"
#include "SceneManager.h"

void Engine::GameManager::Quit()
{

    Windows->close();
    exit(0);
}



void Engine::GameManager::GameLoop()
{

    while (Windows->isOpen())
    {
        
        DeltaTime = ClockDeltaTime.restart().asSeconds();

        G_SceneManager->GetCurrentScene()->S_Update();
        S_Input();
        G_SceneManager->GetCurrentScene()->S_Simulation();
        G_SceneManager->GetCurrentScene()->S_Syteme();
        Windows->clear();
        G_SceneManager->GetCurrentScene()->S_Render();
        Windows->display();

    }
}

void Engine::GameManager::S_Input()
{
    sf::Event event;
    while (Windows->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Quit();
        else if (event.type == sf::Event::Resized) {
            ResizeView(event);
        }
        G_SceneManager->GetCurrentScene()->S_Action(event);
    }
}

void Engine::GameManager::ResizeView(sf::Event event)
{
	float aspectratio = float(Windows->getSize().x / Windows->getSize().y);
	View.setSize(View_Height * aspectratio, View_Height);
}


