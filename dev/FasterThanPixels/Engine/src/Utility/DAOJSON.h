#pragma once
#include <string>
#include "json.hpp"

namespace Engine {
	struct DBConnectionInfo {
		std::string Path;
	};
	class DAO {
	private:
		DBConnectionInfo DB_Info;
	public:
		DAO(DBConnectionInfo dbinfo);
		void CreateDB(const std::string Path, std::map<std::string, std::string>& data, std::string playerName);
		void InsertData(const std::string Path, std::map<std::string, std::string>& data, std::string playerName);
		std::map<std::string, std::string>GetData(std::string path);
		bool isFollowingPattern(std::map<std::string, std::string>& data);
	};
}