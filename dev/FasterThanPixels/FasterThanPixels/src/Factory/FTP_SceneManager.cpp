#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"
#include "../Scene/Authentification.h"

void FTP_SceneManager::Init(std::string FirstScene)
{
	Starting* st =  new Starting("Cinematique",this);
	Authentification* authentification = new Authentification("Authentification", this);

	AddScene(st);
	AddScene(authentification);
	CurrentScene = FirstScene;

	GetCurrentScene()->S_Begin_Play();



}

FTP_SceneManager::FTP_SceneManager(Engine::GameManager* gm)
	:SceneManager(gm)
{

}
