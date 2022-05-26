#include "DAOJSON.h"
#include <vector>
#include <iostream>
#include <fstream>

Engine::DAO::DAO(DBConnectionInfo dbinfo)
{
	DB_Info = dbinfo;
}

void Engine::DAO::CreateDB(const std::string Path, std::map<std::string, std::string>& data, std::string playerName)
{
}

void Engine::DAO::InsertData(const std::string Path, std::map<std::string, std::string>& data, std::string playerName) {

	std::string filename = Path+playerName+".json";
	nlohmann::json userdata(data);
	std::ofstream file(filename);
	file << userdata;

}

std::map<std::string, std::string> Engine::DAO::GetData(std::string path) {
	nlohmann::json j;
	std::map < std::string, std::string> data;
	std::ifstream settings_file(path);
	settings_file >> j;
	data = j;

	return data;
}

bool Engine::DAO::isFollowingPattern(std::map<std::string, std::string>& data)
{

	std::vector<std::string> pattern{ "Username","Mail","Password","Level","Interceptor","Bomber","Fighter","Carrier","Turret","Asteroid","Castaway","Mission" };
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

