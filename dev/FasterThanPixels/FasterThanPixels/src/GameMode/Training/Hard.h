#pragma once
#include "Engine.h"
/*! \class FTP_Training_Hard
* \brief classe enfant de Gamemode, represente le mode de jeu "Training_Hard"
*
*/
class FTP_Training_Hard : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};
