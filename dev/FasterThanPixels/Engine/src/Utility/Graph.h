#pragma once
#include <vector>
#include <string>
namespace Engine {
	/*! \class Graph_Gamemodes
	* \brief classe qui g�n�re un noeud pour un graphe, Utile pour savoir quel gamemode peut etre enchain� sans avoir de doublon.
	*/
	class Graph_Gamemodes {
		std::vector<Graph_Gamemodes*> ConnectedGamemode; /*!< Tous les autres gamemodes que celui-ci peux enchainer */
	public:
		std::string NameGamemode; /*!< Nom du gamemode */
		/*!
		*  \brief GetRandomGamemode
		*
		*  Return un mode de jeu random qui peut etre enchain� apr�s celui-ci
		* \return un autre noeud qui represente un autre gamemode
		*/
		Graph_Gamemodes* GetRandomGamemode();
		/*!
		*  \brief AddGameMode
		*
		*  Ajoute un gamemode disponible apr�s ce noeud
		* \param othergm : Autre gamemode qui peut �tre enchain� apr�s celui-ci
		*/
		void AddGameMode(Graph_Gamemodes* othergm);
	};
}