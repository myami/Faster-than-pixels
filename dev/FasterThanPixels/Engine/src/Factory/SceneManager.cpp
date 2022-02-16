#include "SceneManager.h"
#include "../Utility/Scene.h"

Engine::Scene& Engine::SceneManager::GetScene(std::string sc)
{
	for (size_t i = 0; i < M_Scene.size(); i++)
	{
		if (M_Scene[i]->S_Name == sc) {
			return *M_Scene[i];
		}
	}
}

Engine::Scene& Engine::SceneManager::GetCurrentScene(std::string scene)
{
	for (size_t i = 0; i < M_Scene.size(); i++)
	{
		if (M_Scene[i]->S_Name == scene) {
			return *M_Scene[i];
		}
	}
}

void Engine::SceneManager::AddScene(Engine::Scene* scene)
{
	M_Scene.push_back(scene);
}
