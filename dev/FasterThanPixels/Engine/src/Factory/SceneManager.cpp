#include "SceneManager.h"
#include "GameManager.h"
#include "../Utility/StateMachine/State.h"
#include "../Utility/Scene.h"

Engine::SceneManager::SceneManager():FiniteStateMachine()
{
}


void Engine::SceneManager::Reset_FSM()
{
	this->Current_States = this->Initial_States;
	GetCurrentScene()->Begin_Play();
}

bool Engine::SceneManager::Run_FSM()
{
	if (GetCurrentScene()->param.StopState) {
		if (!GetCurrentScene()->param.isterminal) {
			ChangeScene(GetCurrentScene()->param.NextScene);
		}
		else {
			this->Stop_FSM();
			return true;
		}
	}
	else {
		GetCurrentScene()->Tick();
	}
	return false;
}

Engine::SceneManager::SceneManager(Engine::GameManager* gm)
{
	this->_GameManager = gm;
}

Engine::Scene* Engine::SceneManager::GetScene(std::string sc)
{
	return dynamic_cast<Scene*>(this->FindByName(sc));
}

Engine::Scene* Engine::SceneManager::GetCurrentScene()
{
	return dynamic_cast<Scene*>(this->Current_States);
}

void Engine::SceneManager::AddScene(Engine::Scene* scene)
{
	this->Add_States(scene);
}

void Engine::SceneManager::ChangeScene(std::string newscene)
{
	Transit_To(FindByName(newscene));
}

Engine::SceneManager::~SceneManager()
{
	
}

Engine::FSM_State* Engine::SceneManager::GetStatesFromScene(Engine::Scene* sc)
{
	return dynamic_cast<FSM_State*>(sc);
}
