#pragma once
#include "../ECS/Entity.h"
#include <map>
#include <string>
#include "box2d/box2d.h"
#include "../Utility/StateMachine/StateMachine.h"

namespace Engine {
	/*! \enum EntityState
	* \brief enum representant les etats possibles pour les entite en files d'attente.
	*
	*/
	enum class EntityState {
		None,
		Add,
		Delete
	};
	/*! \struct S_Delay_Entity
	* \brief struct representant les entites en file d'attente.
	*
	*/

	struct S_Delay_Entity {
		int E_ID;
		EntityState E_State;
		std::string E_Tag;
		bool IsAnimated;
	};
	class GameManager;
	class StateMachine;
	/*! \class EntityManager
	* \brief classe representant toutes les entités de la scène.
	*/
	class EntityManager : public StateMachine {
	public:
		std::vector<Engine::Entity*> M_EntityVector; /*!< Liste des Entite */
		std::vector<S_Delay_Entity> M_EntityToChange; /*!< Liste des entites qui doivent etre changer au debut de la prochaine frame */
		std::map<b2Body*, int> M_PhysicMap;  /*!< Liste des body de la simulation relie a leur entite */
		Engine::GameManager* GameManager; /*!< Game Manager*/

		EntityManager();

		/*!
	    * \brief GenerateEntity
	    *
	    * Au debut de la scene, genere toutes les entités disponibles.
	    */
		virtual void GenerateEntity(Scene* sc) = 0;
		/*!
		* \brief Met a jour toutes les entités
		*
		* Appelé au debut du gameloop, cette function permait de mette a jour toutes les entités de M_EntityToChange, dans M_EntityVector et M_EntityMap avant tout autre utilisation des entités.
		*/
		void Update();
		/*!
		* \brief Demande une entite libre
		*
		* \return une entite libre d utilisatation
		*/
		int RequestEntity(std::string tag);
		/*!
		* \brief Retourne les entités qui peuvent être dessinées à l'écran.
		*
		* \return un vecteur d'entité
		*/
		std::vector<Engine::Entity*> EntityToDraw();
		/*!
		*  \brief Retourne les entités qui ont toutes un même components.
		*  \param name : Nom du components
		*  
		* \return un vector d'entite
		*/
		std::vector<Engine::Entity*> GetAllEntityWithComponent(std::string Component);
		/*!
		* \brief Retourne une entité qui à l'ID du paramètre.
		* \param int id : id du components
		* \return une entite
		*/
		Engine::Entity* GetEntityWithId(int id);
		/*!
		* \brief Retoune true si il y a des entités dans la file d'attente.
		*
		* \return Booléen
		*/
		bool AsEntityWaiting();
		/*!
		* \brief Ajoute une entite dans la liste d'attente.
		*
		* \param S_Delay_Entity entite : structure de l'entite
		*/
		void AddToWaiting(S_Delay_Entity entite);
		/*!
		* \brief Retourne les entités qui ont toutes un même tag.
		* \param name : Nom du tag
		* \return Un vecteur d'entité.
		*/
		std::vector<Engine::Entity*> GetAllEntityWithTag(std::string Tag);
		/*!
		* \brief Fin de traitement de l'entité.
		* \param Entity entity : entite
		* \param EntityState entitystate : states
		* Une fois l'entité a fini dans la liste d'attente, lui faire des actions.
		*/

		virtual void EntityEndWaiting(Engine::Entity* entity, EntityState entitystate) = 0;

	private:
		/*!
		* \brief Appel de la fonction nécessaire à la struct.
		* Prend struct par struct dans la waiting list et call la function qu elle a besoin entre les 4 disponibles
		*/
		void EntityWaitingListDispatch();
		/*!
		* \brief Flush le contenu d'une entité.
		*
		* Si une entite dans M_EntityToChange, la variable "E_CanBeUsed" est differente alors appele cette function et la vide de ces components et change sont etat pour etre utilisable pour une autre entite
		*/
		Engine::Entity* RemoveEntity(S_Delay_Entity entite);
		/*
		* \brief Ajoute une entite à partir de la struct.
		*/
		Engine::Entity* AddEntity(S_Delay_Entity entite);
	};
}