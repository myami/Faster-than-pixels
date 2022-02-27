#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "sqlite/sqlite3.h"


namespace Engine {
	class Entity;
	std::vector<nlohmann::json> LoadAssetFromFile();
	nlohmann::json GetPlayerInfoFromDB(std::string Name);
	bool LoginUser(std::string name, std::string passwd);
	void CreateUser(std::string name, std::string passwd);
	void SetPlayerInfo(nlohmann::json newinfo);

	std::vector<Entity> ObjectCollide(); // liste de tout les objet qui sont rentre en collision dans box2d a la frame actuelle

}