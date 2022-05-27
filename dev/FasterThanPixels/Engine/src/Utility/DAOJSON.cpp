#include "DAOJSON.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

Engine::DAOJSON::DAOJSON(DBConnectionInfo dbinfo)
{
	db_info = dbinfo;
}

void Engine::DAOJSON::CreateDB()
{
	std::filesystem::create_directory(db_info.Path);

}

void Engine::DAOJSON::InsertData(std::map<std::string, std::string>& data, std::vector<std::string>& pattern)
{
	std::string filename = db_info.Path + db_info.Username + ".json";
	nlohmann::json userdata(data);
	std::ofstream file(filename);
	file << userdata;
	std::cout << "Sauvegarde réussie" << std::endl;

	/*if (isFollowingPattern(data, pattern))
	{

	}
	else {
		std::cout << "Clefs de map incorrectes" << std::endl;
	}*/
}


std::map<std::string, std::string> Engine::DAOJSON::GetData() {
	nlohmann::json j;
	std::map <std::string, std::string> data;
	std::ifstream user_file(db_info.Path+db_info.Username+".json");
	user_file >> j;
	data = j;

	return data;
}

bool Engine::DAOJSON::isFollowingPattern(std::map<std::string, std::string>& data, std::vector<std::string>& pattern)
{

	std::vector<std::string> key;

	for (auto it = data.begin(); it != data.end(); ++it) {
		key.push_back(it->first);
	}

	for (size_t i = 0; i < pattern.size(); i++) {
		if (!pattern[i]._Equal(key[i]))
			return false;
	}
	return true;
}
