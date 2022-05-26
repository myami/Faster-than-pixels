#include "DAOJSON.h"
#include <vector>
#include <iostream>
#include <fstream>

Engine::DAOJSON::DAOJSON(DBConnectionInfo dbinfo)
{
	DB_Info = dbinfo;
}

void Engine::DAOJSON::CreateDB(const std::string Path, std::map<std::string, std::string>& data)
{
	std::string filename = Path +".json";
	nlohmann::json userdata(data);
	std::ofstream file(filename);
	file << userdata;

}

void Engine::DAOJSON::InsertData(const std::string Path, std::map<std::string, std::string>& data, std::vector<std::string>& pattern)
{
	if (isFollowingPattern(data, pattern))
	{
		std::string filename = Path + ".json";
		nlohmann::json userdata(data);
		std::ofstream file(filename);
		file << userdata;
	}
	else {
		std::cout << "Clefs de map incorrectes" << std::endl;
	}
}


std::map<std::string, std::string> Engine::DAOJSON::GetData(std::string path) {
	nlohmann::json j;
	std::map < std::string, std::string> data;
	std::ifstream settings_file(path);
	settings_file >> j;
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
