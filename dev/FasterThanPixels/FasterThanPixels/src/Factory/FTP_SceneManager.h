#pragma once
#include "Engine.h"
#include "..\Scene\Starting.h"
class FTP_SceneManager : public Engine::SceneManager {
public:
	void Init();
	FTP_GameManager* _GameManager;
	FTP_SceneManager(FTP_GameManager* gm);

};