#pragma once

#include "Engine.h"
#include "../Utility/FTP_DAO.h"

/*! \class FTP_GameManager
* \brief classe enfant de GameManager
*
*/
class FTP_GameManager : public Engine::GameManager {
public:
	void Game_Init(std::string NameOfTheGame, std::string FirstScene);	// initialiser toutes les donnes du jeu
	std::string UserName;
	FTP_GameManager();
	FTP_DAO* Dao;
	std::map < std::string, int> Settings;
};
