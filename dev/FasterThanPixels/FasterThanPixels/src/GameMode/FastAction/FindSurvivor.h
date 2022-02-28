#pragma once
#include "Engine.h"
/*! \class FTP_FindSurvivor
* \brief classe enfant de Gamemode, represente le mode de jeu "FindSurvivor"
*
*/
class FTP_FindSurvivor : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};

