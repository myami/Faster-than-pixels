#pragma once
#include "Engine.h"
class FTP_FindSurvivor : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};

