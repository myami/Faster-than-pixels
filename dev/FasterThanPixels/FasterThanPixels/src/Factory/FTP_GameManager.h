#pragma once
#include "Engine.h"
/*! \class FTP_GameManager
* \brief classe enfant de GameManager
*
*/
class FTP_GameManager : public Engine::GameManager {
public:
	 void Game_Init(); // initialiser toutes les donnes du jeu
	 void GameLoop();// loop principale du jeu
	 void Quit();
	 void S_Input(); // gerer les events de sfml (input)
};
