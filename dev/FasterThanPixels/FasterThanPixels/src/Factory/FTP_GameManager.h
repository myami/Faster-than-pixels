#pragma once
#include "Engine.h"
/*! \class FTP_GameManager
* \brief classe enfant de GameManager
*
*/
class FTP_GameManager : public Engine::GameManager {
public:
	 void Game_Init(std::string NameOfTheGame, std::string FistScene); // initialiser toutes les donnes du jeu
};
