#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "../Sqlite/include/sqlite/sqlite3.h" // Fix temporaire
#include "SFML/Graphics.hpp"
#include "../Factory/EntityManager.h"


namespace Engine {
	class Entity;
	/*!
	*  \brief LoadAssetFromFile
	*
	*  Charge tout les assets du dossier assets dans un vector de JSON
	* \return liste de tout les JSON dispo dans le dossier Assets
	*/
	std::vector<nlohmann::json> LoadAssetFromFile(std::string Path);



	/*!
	*  \brief GetPlayerInfoFromDB
	*
	*  Retourne un JSON de la BDD avec toutes les donners actuelle du joueur
	* \param Name : Nom du joueur
	* \return json du joueur de la bdd
	*/
	nlohmann::json GetPlayerInfoFromDB(std::string Name);
	/*!
	*  \brief LoginUser
	*
	*  Connecte le joueur au jeu
	* \param name : Nom du joueur
	* \param passwd : mot de passe du joueur
	* \return true si le joueur existe et ces bien connecter
	*/
	bool LoginUser(std::string name, std::string passwd);
	/*!
	*  \brief CreateUser
	*
	*  Inscrit le joueur au jeu
	* \param name : Nom du joueur
	* \param passwd : mot de passe du joueur
	*/
	void CreateUser(std::string name, std::string passwd);
	/*!
	*  \brief SetPlayerInfo
	*
	*  Modifie les infos du joueur dans la bdd
	* \param newinfo : JSON de la bdd du joueur avec les nouvelles infos
	*/
	void SetPlayerInfo(nlohmann::json newinfo);
	/*!
	*  \brief ObjectCollide
	*
	*  Return une liste d'entite qui sont rentrer en collision dans box2d
	* \return liste d'entite 
	*/

	std::vector<Entity> ObjectCollide();
	/*!
	*  \brief GenerateEnvironnement
	*
	*  Return une liste d'entite qui sont l environnement de la map
	* \param seed : le seed du joueur
	* \return liste d'entite
	*/

	void InitEnvironnement(int seed, Engine::EntityManager* entman);

}