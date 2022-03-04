#include "GameManager.h"
#include "AssetManager.h"
#include "SceneManager.h"

void Engine::GameManager::Quit()
{
    Windows->close();
}



void Engine::GameManager::GameLoop()
{

    while (Windows->isOpen())
    {
        G_SceneManager->GetCurrentScene().S_Update();
        S_Input();
        G_SceneManager->GetCurrentScene().S_Simulation();
        G_SceneManager->GetCurrentScene().S_Syteme();
        Windows->clear();
        G_SceneManager->GetCurrentScene().S_Render();
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
        G_SceneManager->GetCurrentScene().S_Action(event);
    }
}

void Engine::GameManager::ResizeView(sf::Event event)
{
	float aspectratio = float(Windows->getSize().x / Windows->getSize().y);
	View.setSize(View_Height * aspectratio, View_Height);
}

void Engine::GameManager::ChangeScene(std::string newscene)
{
	G_SceneManager->GetCurrentScene().S_End_Scene();
	CurrentScene = newscene;
	G_SceneManager->GetCurrentScene().S_Begin_Play();

}
