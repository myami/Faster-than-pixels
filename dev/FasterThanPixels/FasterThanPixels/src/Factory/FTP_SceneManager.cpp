#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"

void FTP_SceneManager::Init()
{
	Starting* st =  new Starting("Cinematique",_GameManager);
	AddScene(st);



}

FTP_SceneManager::FTP_SceneManager(FTP_GameManager* gm)
{
	this->_GameManager = gm;
}
