#include "BlankScene.h"
#include "Scene.h"

Engine::BlankScene::BlankScene(std::string name) : Engine::Scene(name)
{
}

void Engine::BlankScene::Tick()
{
}

void Engine::BlankScene::S_Render()
{
}

void Engine::BlankScene::S_ActionTrigger(std::string ActionName)
{
}

void Engine::BlankScene::Begin_Play()
{
}

void Engine::BlankScene::End_Play()
{
}

void Engine::BlankScene::S_Input_Mouse(sf::Event event)
{
}

void Engine::BlankScene::S_Input_Text(sf::Event event)
{
}

void Engine::BlankScene::S_Static_Physic(b2Body* body)
{
}

void Engine::BlankScene::S_Dynamic_Physic(b2Body* body)
{
}

void Engine::BlankScene::S_Kynematic_Physic(b2Body* body)
{
}