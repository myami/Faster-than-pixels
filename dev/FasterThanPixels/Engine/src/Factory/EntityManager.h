#pragma once
#include "../ECS/Entity.h"
#include <map>
#include <string>
namespace Engine {
	/*! \class EntityManager
	* \brief classe representant tout les entite de la scene
	*
	*/
	class EntityManager {
	public:
		std::vector<Engine::Entity*> M_EntityVector; /*!< Liste des Entite */
		std::map<std::string, std::vector<Engine::Entity*>> M_EntityMap; /*!< Liste des Entite par tag */
		std::vector<Engine::Entity*> M_EntityToChange; /*!< Liste des entites qui doivent etre changer au debut de la prochaine frame */
		int M_TotalEntity; /*!< Le nombre total d'entite disponible dans le pool */
		/*!
	   *  \brief GenerateEntity
	   *
	   *  Au debut de la scene, genere toutes els entite disponibles
	   */
		void GenerateEntity(); 
		/*!
		*  \brief Update
		*
		*  Appeler au debut du gameloop, cette function permait de mette a jour toutes les entite de M_EntityToChange, dans M_EntityVector et M_EntityMap avant toute autre utilisation des entites
		*/
		void Update(); 
		/*!
		*  \brief RemoveEntity
		*
		*  Si une entite dans M_EntityToChange la variable "E_CanBeUsed" est differente alors appele cette function et la vide de ces components et change sont etat pour etre utilisable pour une autre entite
		*/
		void RemoveEntity(); 
		/*!
		*  \brief RequestEntity
		*
		*  Demande une entite libre 
		* \return une entite libre d utilisatation
		*/
		Engine::Entity* RequestEntity();

		void EntityChangeMap(Engine::Entity* entite,std::string oldmap, std::string newmap);

	};
}