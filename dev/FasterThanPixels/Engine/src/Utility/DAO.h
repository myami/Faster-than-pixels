#pragma once
//#include "jdbc/mysql_connection.h"
#include "sqlite/sqlite3.h"
namespace Engine {
	struct DBConnectionInfo {
		std::string IpAdress;
		std::string UserName;
		std::string Password;
		std::string DbName;

	};
	class DAO {
	private:
		DBConnectionInfo DB_Info;
	public:
		DAO(DBConnectionInfo dbinfo);
		void Connection();
		void Disconnect();
		bool IsConnected();

	};
}