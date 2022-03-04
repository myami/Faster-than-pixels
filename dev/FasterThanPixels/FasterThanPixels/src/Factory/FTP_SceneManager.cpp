#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"

void FTP_SceneManager::Init(std::string FirstScene)
{
	Starting* st =  new Starting("Cinematique",this);
	AddScene(st);
	CurrentScene = FirstScene;

}

FTP_SceneManager::FTP_SceneManager(Engine::GameManager* gm)
	:SceneManager(gm)
{

}
