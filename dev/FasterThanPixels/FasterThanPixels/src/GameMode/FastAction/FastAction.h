#pragma once
#include "Engine.h"
class FTP_FastAction : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};