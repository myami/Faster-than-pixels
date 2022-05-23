#pragma once
#include "../ECS/Entity.h"
#include <map>
#include <string>
#include "box2d/box2d.h"
#include "../Utility/StateMachine/StateMachine.h"

namespace Engine {
	/*! \class EntityManager
	* \brief classe representant tout les entite de la scene
	*
	*/
	enum class EntityState {
		None,
		Add,
		Delete
	};

	struct S_Delay_Entity {
		int E_ID;
		EntityState E_State;
		std::string E_Tag;
		bool IsAnimated;
	};
	class GameManager;
	class StateMachine;
	class EntityManager : public StateMachine {
	public:
		std::vector<Engine::Entity*> M_EntityVector; /*!< Liste des Entite */
		std::vector<S_Delay_Entity> M_EntityToChange; /*!< Liste des entites qui doivent etre changer au debut de la prochaine frame */
		std::map<b2Body*, int> M_PhysicMap;  /*!< Liste des body de la simulation relie a leur entite */
		Engine::GameManager* GameManager;

		EntityManager();

		/*!
	   *  \brief GenerateEntity
	   *
	   *  Au debut de la scene, genere toutes les entite disponibles
	   */
		virtual void GenerateEntity(Scene* sc) = 0; 
		/*!
		*  \brief Update
		*
		*  Appeler au debut du gameloop, cette function permait de mette a jour toutes les entite de M_EntityToChange, dans M_EntityVector et M_EntityMap avant toute autre utilisation des entites
		*/
		void Update();
		/*!
		*  \brief RequestEntity
		*
		*  Demande une entite libre
		* \return une entite libre d utilisatation
		*/
		int RequestEntity(std::string tag);

		std::vector<Engine::Entity*> EntityToDraw();

		std::vector<Engine::Entity*> GetAllEntityWithComponent(std::string Component);
		Engine::Entity* GetEntityWithId(int id);

		bool AsEntityWaiting();

		void AddToWaiting(S_Delay_Entity entite);
		std::vector<Engine::Entity*> GetAllEntityWithTag(std::string Tag);

		virtual void EntityEndWaiting(Engine::Entity* entity, EntityState entitystate) = 0;

	private:
		/*!
		* \brief EntityWaitingListDispatch
		* Prend struct par struct dans la waiting list et call la function qu elle a besoin entre les 4 disponibles
		*
		*/
		void EntityWaitingListDispatch();
		/*!
		*  \brief RemoveEntity
		*
		*  Si une entite dans M_EntityToChange la variable "E_CanBeUsed" est differente alors appele cette function et la vide de ces components et change sont etat pour etre utilisable pour une autre entite
		*/
		Engine::Entity* RemoveEntity(S_Delay_Entity entite);
		/*
		* \brief AddEntity Ajoute une entite a partir de la struct
		*/
		Engine::Entity* AddEntity(S_Delay_Entity entite);
	};
}