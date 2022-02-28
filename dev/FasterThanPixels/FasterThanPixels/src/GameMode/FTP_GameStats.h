#pragma once
#include "Engine.h"
/**
* Une structure qui represente les infos d une partie 
 */

struct FTP_Game_Info {
	float ScoreTotal; /*!< Score total du joueur */
	int NB_Intercepteur_kill; /*!< Nombre d'enemie de type intercepteur tuer */
	int NB_Bombardier_kill;  /*!< Nombre d'enemie de type Bombardier tuer */
	int NB_Chasseur_kill;  /*!< Nombre d'enemie de type Chasseur tuer */
	int NB_PortesVaiseau_kill;  /*!< Nombre d'enemie de type PortesVaiseau tuer */
	int NB_Asteroid_Destroy;  /*!< Nombre Asteroid detruit */
	bool IsTraining; /*!< Si le joueur est en mode training */
	int PeopleSaves; /*!< nombre de personnes sauver */
	std::vector<std::string> GamemodesJouer; /*!< Listes de mode jouer */

};
/*! \class FTP_GameStats
* \brief classe enfant de GameStats
*
*/
class FTP_GameStats : public Engine::GameStats {
public :
	FTP_Game_Info InfoGame;
};