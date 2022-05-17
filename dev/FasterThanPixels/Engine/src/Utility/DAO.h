#pragma once
//#include "jdbc/mysql_connection.h"
#include "sqlite/sqlite3.h"
namespace Engine {
	struct DBConnectionInfo {
		std::string DbName;
	};
	class DAO {
	private:
		DBConnectionInfo DB_Info;
	public:
		DAO(DBConnectionInfo dbinfo);
		void Connection(std::string DBname);
		void Disconnect();
		void InsertData(std::string DBName, std::string Query);
		sqlite3* db;	
	};
}