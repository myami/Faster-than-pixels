#pragma once
#include "Engine.h"
/*! \class FTP_Race
* \brief classe enfant de Gamemode, represente le mode de jeu "Race"
*
*/
class FTP_Race : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};
