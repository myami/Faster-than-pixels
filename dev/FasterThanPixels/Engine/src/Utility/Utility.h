#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "sqlite/sqlite3.h"


namespace Engine {
	std::vector<nlohmann::json> LoadAssetFromFile();
	nlohmann::json GetPlayerInfoFromDB(std::string Name);
	bool LoginUser(std::string name, std::string passwd);
	void CreateUser(std::string name, std::string passwd);
	void SetPlayerInfo(nlohmann::json newinfo);

}