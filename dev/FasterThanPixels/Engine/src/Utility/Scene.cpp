#include "Scene.h"

void Engine::Scene::RegisterAction(int key, std::string ActionName)
{
	ActionScene.insert({key,ActionName});
}
