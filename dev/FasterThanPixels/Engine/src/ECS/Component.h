#pragma once
#include <vector>
#include <string>
/*!
 * \file Component.h
 * \brief Composant d une entite qui sauvegarde des variables
 * \version 0.1
 */
namespace Engine {
	class Entity;
	 class Component  {
		 //chaque component a seulement des variables
	 public:
		 std::vector<std::string> RequireComponent; // Si le component a besoin d autre pour fonctionner correctement
		 bool AsRequireComponent(Entity entite);
	};
}
