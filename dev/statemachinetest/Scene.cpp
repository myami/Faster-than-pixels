#include "Scene.h"

Scene::Scene(std::string name):FSM_State()
{
	param.StateName = name;
}

void Scene::Begin_Play()
{
}

void Scene::Tick()
{
}

void Scene::End_Play()
{
}
