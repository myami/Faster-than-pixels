//#pragma once
////#include "jdbc/mysql_connection.h"
//#include "sqlite/sqlite3.h"
//#include <string>
//
//namespace Engine {
//	struct DBConnectionInfo {
//		std::string DbName;
//		std::string Path;
//	};
//	class DAO {
//	private:
//		DBConnectionInfo DB_Info;
//	public:
//		DAO(DBConnectionInfo dbinfo);
//		int CreateDB();
//		int CreateTable(const char* Path,std::string query);
//		int InsertData(const char*, std::string Query);
//		static int callback(void *Notused, int argc, char **argv, char **azColname);
//		sqlite3* db;	
//	};
//}