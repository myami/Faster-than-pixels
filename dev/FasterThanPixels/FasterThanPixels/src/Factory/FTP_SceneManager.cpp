#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"

void FTP_SceneManager::Init()
{
	std::shared_ptr<Starting> st = std::shared_ptr<Starting>();
	st->S_Name = "Cinematique";
	AddScene(st);
}
