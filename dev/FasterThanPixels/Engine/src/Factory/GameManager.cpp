#include "GameManager.h"
#include "AssetManager.h"
#include "SceneManager.h"

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
