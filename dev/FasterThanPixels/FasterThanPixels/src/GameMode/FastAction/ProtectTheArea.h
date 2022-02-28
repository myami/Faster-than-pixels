#pragma once
#include "Engine.h"
/*! \class FTP_ProtectTheArea
* \brief classe enfant de Gamemode, represente le mode de jeu "ProtectTheArea"
*
*/
class FTP_ProtectTheArea : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};
