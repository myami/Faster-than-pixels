#pragma once
#include "Engine.h"


struct FTP_Game_Info { // les infos qu on va afficher sur le menu de stat a la fin de la game et qu on peux sauvegarder a la fin dans la bdd
	float ScoreTotal;
	int NB_Intercepteur_kill;
	int NB_Bombardier_kill;
	int NB_Chasseur_kill;
	int NB_PortesVaiseau_kill;
	int NB_Asteroid_Destroy;
	bool IsTraining;
	int PeopleSaves;
	std::vector<std::string> GamemodesJouer;





};
class FTP_GameStats : public Engine::GameStats {
public :
	FTP_Game_Info InfoGame;
};