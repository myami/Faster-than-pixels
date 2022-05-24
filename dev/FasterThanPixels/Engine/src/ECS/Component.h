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
	 class Component  {
		 //chaque component a seulement des variables
	 public:
		 std::vector<std::string> RequireComponent; /*!< Liste des composant requis si il a des dependances*/
		 std::map<std::string, std::any> ValueToChange; /*!< Valeur a changer sur les variables du component au prochain update du gameloop */
		 std::string C_Name;
		 Component();
		 Component(std::string name);
		 virtual void PrintName() = 0;
	};
}
