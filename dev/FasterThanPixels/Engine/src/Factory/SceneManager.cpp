#include "SceneManager.h"
#include "GameManager.h"
#include "../Utility/Scene.h"

Engine::SceneManager::SceneManager()
{
}

Engine::SceneManager::SceneManager(Engine::GameManager* gm)
{
	this->_GameManager = gm;

}

Engine::Scene& Engine::SceneManager::GetScene(std::string sc)
{
	for (size_t i = 0; i < M_Scene.size(); i++)
	{
		if (M_Scene[i]->S_Name == sc) {
			return *M_Scene[i];
		}
	}
}

Engine::Scene& Engine::SceneManager::GetCurrentScene()
{
	for (size_t i = 0; i < M_Scene.size(); i++)
	{
		if (M_Scene[i]->S_Name == CurrentScene) {
			return *M_Scene[i];
		}
	}
}

void Engine::SceneManager::AddScene(Engine::Scene* scene)
{
	M_Scene.push_back(scene);
}

void Engine::SceneManager::ChangeScene(std::string newscene)
{
	GetCurrentScene().S_End_Scene();
	CurrentScene = newscene;
	GetCurrentScene().S_Begin_Play();
}
