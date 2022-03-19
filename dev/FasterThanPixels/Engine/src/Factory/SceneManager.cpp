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
	for (auto scene : M_Scene)
	{
		if (scene->S_Name == sc) {
			return *scene;
		}
	}
}

Engine::Scene* Engine::SceneManager::GetCurrentScene()
{
	for (auto scene : M_Scene)
	{
		if (scene->S_Name == CurrentScene) {
			
			return scene;
		}
	}
}

void Engine::SceneManager::AddScene(Engine::Scene* scene)
{
	M_Scene.push_back(scene);

}

void Engine::SceneManager::ChangeScene(std::string newscene)
{
	GetCurrentScene()->S_End_Scene();
	CurrentScene = newscene;
	GetCurrentScene()->S_Begin_Play();
}

Engine::SceneManager::~SceneManager()
{
	for (auto s : M_Scene) {
		delete s;
	}
}
