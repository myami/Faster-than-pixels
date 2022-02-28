#pragma once
#include "Engine.h"
/*! \class FTP_FastAction
* \brief classe enfant de Gamemode, represente le mode de jeu "FastAction"
*
*/
class FTP_FastAction : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};