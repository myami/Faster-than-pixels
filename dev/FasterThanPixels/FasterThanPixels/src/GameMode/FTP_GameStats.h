#pragma once
#include "Engine.h"
#include <string>

/**
* Une structure qui represente les infos d une partie 
 */

struct FTP_Game_Info {
	float ScoreTotal; /*!< Score total du joueur */
	float TempsTotal;  /*!< Temps de jeu en minutes */
	std::string Difficulte;  /*!< Difficulte selectionee par le joueur */
	int NB_Intercepteur_kill; /*!< Nombre d'enemie de type intercepteur tuer */
	int NB_Bombardier_kill;  /*!< Nombre d'enemie de type Bombardier tuer */
	int NB_Chasseur_kill;  /*!< Nombre d'enemie de type Chasseur tuer */
	int NB_PortesVaiseau_kill;  /*!< Nombre d'enemie de type PortesVaiseau tuer */
	int NB_Asteroid_Destroy; /*!< Nombre Asteroid detruit */
	float DegatsCauses; /*!< Cumul des degats infliges aux adversaires */
	bool IsTraining; /*!< Si le joueur est en mode training */
	int TotalPeople; /*< Nombre total de personnes a sauver */
	int PeopleSaves; /*!< nombre de personnes sauver */
	float AverageSpeed; /*!< Course : Somme de la distance entre les points de passage divise par le temps en secondes */
	float RemainingHealth;  /*!< Vie restante de la structure a defendre */
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