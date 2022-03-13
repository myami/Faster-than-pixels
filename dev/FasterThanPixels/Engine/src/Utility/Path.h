#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
namespace Engine {
	/*! \class Path
	* \brief classe qui gere les chemins pour une IA par exemple
	*/
	class Path {
	public:
		std::vector<sf::Vector2f> nodes;  /*!< Listes de position */
		/*!
	    *  \brief AddNodes
	    *  Ajoutes une nodes dans la listes 
	    *\param newpos : nouvelles position a ajouter dans le chemins
	    */
		void AddNodes(sf::Vector2f newpos);
		/*!
		*  \brief Getnodes
		*
		*  Return toutes les positions dans une listes 
		* \return liste de position
		*/
		std::vector<sf::Vector2f> Getnodes();
	};
}