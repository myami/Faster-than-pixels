#pragma once
#include "Engine.h"
#include <vector>

/*! \class FTP_DAO
* \brief classe enfant de DAOJSON
*
*/
class FTP_DAO : public Engine::DAOJSON {
public:
	FTP_DAO(Engine::DBConnectionInfo db_info);

	std::vector<std::string> pattern{ "Username","Mail","Password","Level","Interceptor","Bomber","Fighter","Carrier","Turret","Asteroid","Castaway","Mission" };
};