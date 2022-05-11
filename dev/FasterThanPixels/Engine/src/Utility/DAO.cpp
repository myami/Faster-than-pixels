#include "DAO.h"

Engine::DAO::DAO(DBConnectionInfo dbinfo)
{
	DB_Info = dbinfo;
}

bool Engine::DAO::Connection()
{
	return false;
}

void Engine::DAO::Disconnect()
{
}

bool Engine::DAO::IsConnected()
{
	return false;
}
