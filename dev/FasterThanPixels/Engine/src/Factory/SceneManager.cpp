#include "SceneManager.h"
#include "GameManager.h"
#include "../Utility/Scene.h"
#include "../Utility/StateMachine/FiniteStateMachine.h"

void Engine::SceneManager::Reset_FSM()
{
	Current_States = Initial_States;
	Current_States->Begin_Play();
}

bool Engine::SceneManager::Run_FSM()
{
	if (Current_States->param.StopState) {
		if (!Current_States->param.isterminal) {
			ChangeScene(Current_States->param.NextScene);
		}
		else {
			Stop_FSM();
			return true;
		}
	}
	else {
		Current_States->Tick();
	}
	return false;
}



Engine::SceneManager::SceneManager():Engine::FiniteStateMachine()
{
}

Engine::SceneManager::SceneManager(Engine::GameManager* gm)
{
	this->_GameManager = gm;
}

Engine::Scene* Engine::SceneManager::GetScene(std::string sc)
{
	return dynamic_cast<Scene*>(FindByName(sc));
}

Engine::Scene* Engine::SceneManager::GetCurrentScene()
{
	return dynamic_cast<Scene*>(Current_States);
}

void Engine::SceneManager::AddScene(Engine::Scene* scene)
{
	Add_States(scene);
}

void Engine::SceneManager::ChangeScene(std::string newscene)
{
	Transit_To(FindByName(newscene));
}

Engine::SceneManager::~SceneManager()
{
	
}