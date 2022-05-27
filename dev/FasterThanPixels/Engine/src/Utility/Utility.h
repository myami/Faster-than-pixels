#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "SFML/Graphics.hpp"
#include "../Factory/EntityManager.h"
#include "box2d/box2d.h"
#include "json.hpp"

namespace Engine {

	class Entity;
	struct S_Delay_Entity;
	class EntityManager;
	/*!
	*  @def LoadAssetFromFile
	*
	*  Charge tout les assets du dossier assets dans un vector de JSON
	* \return liste de tout les JSON dispo dans le dossier Assets
	*/
	std::vector<nlohmann::json> LoadAssetFromFile(std::string Path);
	/*!
	* @def SerializeData
	*
	* Sauvegarde le dictionnaire dans un fichier JSON
	* \param map : Dictionnaire de int.
	*/
	void SerializeData(std::map<std::string, int>& map);

	/*!
	* @def GetInfoFromJSON
	*
	* Lit un fichier JSON et en extrait un dictionnaire.
	* \param path : le chemin d'accès du JSON
	* \return Un dictionnaire de int.
	*/
	std::map<std::string, int> GetInfoFromJSON(std::string path);

	/*!
	* @def FileExists
	*
	* Vérifie si un fichier existe au chemin spécifié.
	* \param path : le chemin d'accès du Fichier
	* \return Un booléen.
	*/
	bool FileExists(std::string path);

	/*!
	*  @def GeneratePhysicBody
	*
	*  Return une liste d'entite 
	* \param entman : pointeur l'Entity Manager
	* \param identity : l'ID l'entity qui sera liée au body
	* \param position : position dans le World
	* \param bound : Bounding box de l'objet
	* \param type : type de body Box2D
	* \param scale : sclaire de la taille de l'entité
	* \param World : pointeur vers le World box2D
	* \return liste d'entite
	*/
	void GeneratePhysicBody(Engine::EntityManager* entman, int identity, sf::Vector2f position, sf::Vector2f bound, b2BodyType type, int scale, b2World* World);
}