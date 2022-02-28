#pragma once
#include "Engine.h"
/*! \class FTP_AttackTheArea
* \brief classe enfant de Gamemode, represente le mode de jeu "Attack the area"
*
*/
class FTP_AttackTheArea : public Engine::GameMode {
	void OnGameModeStart();
	void OnGameModeUpdate();
	void OnGameModeEnd();
};

