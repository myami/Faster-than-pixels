#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"
#include "../Factory/EntityManager.h"
/*!
 * \file Entity.h
 * \brief Entite qui apparait dans le jeu, il contient les composants
 */
namespace Engine {
	/*! \class Entite
	* \brief classe representant chaque Entite qui est dans le EntityManager
	*
	*/
	class Entity {
		std::map < std::string, Engine::Component*> E_Component; /*!< Liste des components de l'entite */
	public:
		Entity(int id);
		int E_Id = 0; /*!< ID de l'entite */
		std::string E_Tag = "Default"; /*!< Tag de l'entite */
		bool E_CanBeUsed = true; /*!< Si on peux utiliser cette entite ou si elle est utiliser actuellement */
		bool E_IsAnimated = false;

		std::map<std::string, std::any> ValueToChange;/*!< Valeur a changer sur les variables entity au update de la gameloop(Tag ou CanBeUsed) */

		/*!
		 *  \brief Return un component
		 *
		 *	Return un Component que l'entite a
		 *
		 *  \param name : Le nom du component
		 * \return le component qu'on a besoin
		 */
		Engine::Component* GetComponent(std::string name);
		/*!
		 *  \brief Ajoute un component
		 *
		 *	Ajoute un component a l'entite dans un map
		 *
		 *  \param name : Le nom du component
		 *  \param Component : Le component
		 */
		void AddComponent(std::string name, Engine::Component* Component);

		void Reset();

		void DeleteComponent(const std::string name);
	};
}