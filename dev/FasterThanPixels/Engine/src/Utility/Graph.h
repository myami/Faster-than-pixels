#pragma once
#include <vector>
#include <string>
namespace Engine {
	/*! \class Graph_Gamemodes
	* \brief classe qui genere un noeux pour un graphes, Utile pour savoir quel gamemodes peux etre enchainer sans avoir de doublon
	*/
	class Graph_Gamemodes {
		std::vector<Graph_Gamemodes*> ConnectedGamemode; /*!< Tout les autres gamemodes que celui-ci peux enchainer */
	public:
		std::string NameGamemode; /*!< Nom du gamemode */
		/*!
		*  \brief GetRandomGamemode
		*
		*  Return un mode de jeu random qui peux etre enchainer apres celui-ci
		* \return un autre noeud qui represente un autre gamemode
		*/
		Graph_Gamemodes* GetRandomGamemode();
		/*!
		*  \brief AddGameMode
		*
		*  Ajoute un gamemode disponible apres se noeud
		* \param othergm : Autre gamemode qui peux etre enchainer apres celui-ci
		*/
		void AddGameMode(Graph_Gamemodes* othergm);
	};
}