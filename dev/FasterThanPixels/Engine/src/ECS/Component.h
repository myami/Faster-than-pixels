#pragma once
#include <vector>
#include <any>
#include <string>
#include <map>
/*!
 * \file Component.h
 * \brief Composant d une entite qui sauvegarde des variables
 * \version 0.1
 */
namespace Engine {
	class Entity;
	/*! \class Component
     * \brief classe representant chaque composant que l'entite va avoir
     *
     */
	class Component {
	public:
		std::string C_Name; /*!< Nom du component*/
	   /*!
		*  \brief Constructeur vide de Component
		*/
		Component();
		/*!
		 *  \brief Constructeur avec le nom du Component;
		 *  \param name : Le nom du component
		 */
		Component(std::string name);
		/*!
		 *  \brief Affiche le nom du component
		 */
		virtual void PrintName() = 0;
	};
}
