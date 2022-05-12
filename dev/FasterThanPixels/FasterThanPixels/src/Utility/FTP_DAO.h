#pragma once
#include "Engine.h"
#include <vector>
class FTP_DAO : public Engine::DAO {
public:
	//TODO: Init le constructeur (ne pas oublier de call le parent et passer le parametre de connection
	//TODO: cree des function lie a FTP pour les query qui retournes les valeurs rechercher par exemples :
	// USERNAME
	// STATS
	// ACHIEVEMENTS
	std::vector<int> GetPlayerBestScore(std::string PlayerName);
};