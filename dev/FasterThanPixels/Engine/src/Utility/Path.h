#pragma once
#include "Vector2D.h"
#include <vector>
namespace Engine {
	/*! \class Path
	* \brief classe qui gere les chemins pour une IA par exemple
	*/
	class Path {
	public:
		std::vector<Vector2D> nodes;  /*!< Listes de position */
		/*!
	    *  \brief AddNodes
	    *  Ajoutes une nodes dans la listes 
	    *\param newpos : nouvelles position a ajouter dans le chemins
	    */
		void AddNodes(Vector2D newpos);
		/*!
		*  \brief Getnodes
		*
		*  Return toutes les positions dans une listes 
		* \return liste de position
		*/
		std::vector<Vector2D> Getnodes();
	};
}