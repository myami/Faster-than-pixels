#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"

void FTP_SceneManager::Init()
{
	Starting* st =  new Starting("Cinematique");
	AddScene(st);

}
