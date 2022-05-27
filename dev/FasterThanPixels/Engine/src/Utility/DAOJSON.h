#pragma once
#include <string>
#include "json.hpp"

namespace Engine {
	struct DBConnectionInfo {
		std::string Path;
		std::string Username;
	};
	class DAOJSON {	
	public:
		DBConnectionInfo db_info;
		DAOJSON(DBConnectionInfo dbinfo);
		/*!
		*  \brief CreateDB
		*
		*  Cr�er un Json avec les informations d'identifications du joueur
		* \param path : Chemin du r�pertoire
		* \param data : Map contenant les informations du joueur
		*
		*/
		void CreateDB();
		/*!
		*  \brief InsertData
		*
		*  Change les informations dans le Json du joueur
		* \param path : Chemin du r�pertoire
		* \param data : Map contenant les informations du joueur
		*/
		void InsertData(std::map<std::string, std::string>& data, std::vector<std::string>& pattern);
		/*!
		*  \brief GetData
		*
		*  Retourne une map des informations du joueur.
		* \param path : Chemin du r�pertoire
		*/
		std::map<std::string, std::string>GetData();
		/*!
		*  \brief isFollowingPattern
		*
		*  Retourne un bool�en, true si il suit le pattern, false sinon.
		* \param data : Map contenant les informations du joueur
		* \param pattern : Vecteur de String dans un ordre pr�cis
		* \return Un bool�en, true si il suit le pattern, false sinon.
		*/
		bool isFollowingPattern(std::map<std::string, std::string>& data, std::vector<std::string>& pattern);
	};
}