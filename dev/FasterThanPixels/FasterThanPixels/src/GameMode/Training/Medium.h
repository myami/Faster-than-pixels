#pragma once
#include "Engine.h"
/*! \class FTP_Training_Medium
* \brief classe enfant de Gamemode, represente le mode de jeu "Training_Medium"
*
*/
class FTP_Training_Medium : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};
