#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"

void FTP_SceneManager::Init()
{
	Starting* st =  new Starting("Cinematique",this);
	AddScene(st);

}

FTP_SceneManager::FTP_SceneManager(Engine::GameManager* gm)
	:SceneManager(gm)
{

}
