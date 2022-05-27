#pragma once
#include "Engine.h"
/*! \class FTP_Training_Easy
* \brief classe enfant de Gamemode, represente le mode de jeu "Training_Easy"
*
*/
class FTP_Training_Easy : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};
