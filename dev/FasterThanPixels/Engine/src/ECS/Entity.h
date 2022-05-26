#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Component.h"
#include "../Utility/StateMachine/StateParent.h"
/*!
 * \file Entity.h
 * \brief Entite qui apparait dans le jeu, il contient les composants
 */
namespace Engine {
	/*! \class Entite
	* \brief classe representant chaque Entite qui est dans le EntityManager
	*
	*/
	class StateParent;
	class Scene;
	class Entity : public StateParent{
		std::vector<Component*> E_Component; /*!< Liste des components de l'entite */
	public:
		/*!
		 *  \brief Constructeur avec un id
		 *  \param int id: id de l'entite
		 */
		Entity(int id);
		/*!
		 *  \brief Constructeur vide
		 */
		Entity();
		/*!
		 *  \brief Constructeur avec une scene
		 *  \param Scene* sc: Pointeur vers la scene ou l'entite est utiliesr
		 */
		Entity(Scene* sc);
		/*!
		 *  \brief Constructeur avec une scene et un tag
		 *  \param Scene* sc: Pointeur vers la scene ou l'entite est utiliesr
		 *   \param std::string tag: Tag de l'entite
		 */
		Entity(Scene* sc,std::string tag);
		/*!
		 *  \brief Constructeur avec un tag
		 *   \param std::string tag: Tag de l'entite
		 */
		Entity(std::string tag);
		/*!
		 *  \brief Constructeur avec une scene , un tag et un id
		 *  \param Scene* sc: Pointeur vers la scene ou l'entite est utiliesr
		 *   \param std::string tag: Tag de l'entite
		 *  \param int id: id de l'entite
		 */
		Entity(Scene* sc, std::string tag, int id);

		int E_Id = 0; /*!< ID de l'entite */
		std::string E_Tag = "Default"; /*!< Tag de l'entite */
		bool E_CanBeUsed = true; /*!< Si on peux utiliser cette entite ou si elle est utiliser actuellement */
		bool E_IsAnimated = false; /*!< Si l entite est anime */
		Scene* CurrentScene;/*!< La scene ou l'entite est utiliesr */

		std::map<std::string, std::any> ValueToChange;/*!< Valeur a changer sur les variables entity au update de la gameloop(Tag ou CanBeUsed) */
		/*!
		 *  \brief Appeler quand l'entite commence a etre utiliser
		 */
		void Begin_Play() override;
		/*!
		 *  \brief Appeler a chaque tick dans la gameloop
		 */
		void Tick() override;
		/*!
		 *  \brief Appeler a la fin de sont utilisation
		 */
		void End_Play() override;

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
		 *  \param Component : Le component
		 */
		void AddComponent(Engine::Component* Component);
		/*!
		 *  \brief Appeler pour enlever tout les components d une entite
		 */
		void Reset();
		/*!
		 *  \brief Supprime un composant
		 *
		 *	Supprime un composant
		 *  \param std::string name : le nom du component
		 */
		void DeleteComponent(const std::string name);
	};
}