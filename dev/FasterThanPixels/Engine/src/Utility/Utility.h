#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include "sqlite/sqlite3.h"


namespace Engine {
	std::vector<nlohmann::json> LoadAssetFromFile();
	
}