#include "DAO.h"

Engine::DAO::DAO(DBConnectionInfo dbinfo)
{
	DB_Info = dbinfo;
}

void Engine::DAO::Connection(std::string DBName)
{
	int message = 0;
	message = sqlite3_open(DBname, &db);

	if (message) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return(-1);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
		
	Engine::DAO::Disconnect();
	return(0);
}

void Engine::DAO::Disconnect()
{
	sqlite3_close(db);
	std::cout << "La base de donnée à été déconnectée.";
}

void Engine::DAO::InsertData(std::string DBName, std::string Query)
{
	Engine::DAO::Connection(DBName);

	char* messaggeError;
	exit = sqlite3_exec(DB, Query.c_str(), NULL, 0, &messaggeError);

	if (exit != SQLITE_OK) {
		std::cerr << "Erreur lors de l'exécution de la requête." << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Requette exécutée avec succès." << std::endl;
	Engine::DAO::Disconnect()
	return (0);
}
