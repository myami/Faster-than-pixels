#include "DAO.h"

Engine::DAO::DAO(DBConnectionInfo dbinfo)
{
	DB_Info = dbinfo;
}

int CreateDB(const char* Path) {
	sqlite3* DB;

	int message = 0;

	message = sqlite3_open(Path, &DB);

	sqlite3_close(DB);

	return 0;
}

int Engine::DAO::InsertData(const char* Path, std::string Query)
{
	sqlite3* DB;

	try {
		int exit = 0;
		exit = sqlite3_open(Path, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, query.c_str(), callback, 0, &messageError);

		if (exit != SQLITE_OK) {
			std::cerr << "Erreur dans l'insertion de donnée" << std::endl;
			sqlite3_free(messageError);
		}
		else
			std::cout << "Donnée insérées avec succès" << std::endl;
		sqlite3_close(DB);
	}
	catch (const exception& e) {
		std::cerr << e.what();
	}
	sqlite3_close(DB);
	return 0;
}

int Engine::DAO::CreateTable(const char* Path, std::string query)
{
	sqlite3* DB;

	try {
		int exit = 0;
		exit = sqlite3_open(Path, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, query.c_str(), callback, 0, &messageError);

		if (exit != SQLITE_OK) {
			std::cerr << "Erreur dans la création de table" << std::endl;
			sqlite3_free(messageError);
		}
		else
			std::cout << "Table créée avec succès" << std::endl;
		sqlite3_close(DB);
	}
	catch(const exception & e) {
		std::cerr << e.what();
	}
	sqlite3_close(DB);
	return 0;
}

static int callback(void* Notused, int argc, char** argv, char** azColname)
{
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int select_callback(void* p_data, int num_fields, char** p_fields, char** p_col_names)
{
	Records* records = static_cast<Records*>(p_data);
	try {
		records->emplace_back(p_fields, p_fields + num_fields);
	}
	catch (...) {
		// abort select on failure, don't let exception propogate thru sqlite3 call-stack
		return 1;
	}
	return 0;
}
