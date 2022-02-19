#include "Scene.h"

void Engine::Scene::RegisterAction(int key, std::string ActionName)
{

	ActionScene.insert({key,ActionName });
}

Engine::Scene::Scene()
{
}

Engine::Scene::Scene(std::string name)
{
	this->S_Name = name;
}
