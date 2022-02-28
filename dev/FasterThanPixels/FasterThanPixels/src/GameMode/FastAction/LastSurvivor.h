#pragma once
#include "Engine.h"
/*! \class FTP_LastSurvivor
* \brief classe enfant de Gamemode, represente le mode de jeu "LastSurvivor"
*
*/
class FTP_LastSurvivor : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};

