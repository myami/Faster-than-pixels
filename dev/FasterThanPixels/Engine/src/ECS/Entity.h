#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"
/*!
 * \file Entity.h
 * \brief Entite qui apparait dans le jeu, il contient les composants
 * \version 0.1
 */
namespace Engine {
	class Entity {
	public:
		const int E_Id = 0;
		const std::string E_Tag = "Default";
		bool E_CanBeUsed = true; // on genere un pool de x entity dans la ram quand une entite meure, on ne la supprime pas mais on la mais dans un coin pour la reutiliser apres
		std::map < std::string, std::shared_ptr<Engine::Component>> E_Component; // map de tout les composants que l entity utilise
		
		std::shared_ptr<Engine::Component> GetComponent(std::string name);
		void AddComponent(std::string name, std::shared_ptr<Engine::Component> Component);
		virtual void OnColliderEnter() = 0;
	};
}