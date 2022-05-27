#pragma once
#include <string>
#include "json.hpp"

namespace Engine {
	/*! \struct DBConnectionInfo
	* \brief struct representant les information de connections
	*
	*/
	struct DBConnectionInfo {
		std::string Path;
		std::string Username;
	};
	/*! \class DAOJSON
	* \brief classe representant un DAO utilisatn JSON 
	*
	*/
	class DAOJSON {
	public:
		DBConnectionInfo db_info; /*!< Struct DBConnectionInfo */
		DAOJSON(DBConnectionInfo dbinfo);
		/*!
		*  \brief CreateDB
		*
		*  Créer un Json avec les informations d'identifications du joueur
		* \param path : Chemin du répertoire
		* \param data : Map contenant les informations du joueur
		*
		*/
		void CreateDB();
		/*!
		*  \brief InsertData
		*
		*  Change les informations dans le Json du joueur
		* \param path : Chemin du répertoire
		* \param data : Map contenant les informations du joueur
		*/
		void InsertData(std::map<std::string, std::string>& data, std::vector<std::string>& pattern);
		/*!
		*  \brief GetData
		*
		*  Retourne une map des informations du joueur.
		* \param path : Chemin du répertoire
		*/
		std::map<std::string, std::string>GetData();
		/*!
		*  \brief isFollowingPattern
		*
		*  Retourne un booléen, true si il suit le pattern, false sinon.
		* \param data : Map contenant les informations du joueur
		* \param pattern : Vecteur de String dans un ordre précis
		* \return Un booléen, true si il suit le pattern, false sinon.
		*/
		bool isFollowingPattern(std::map<std::string, std::string>& data, std::vector<std::string>& pattern);
	};
}