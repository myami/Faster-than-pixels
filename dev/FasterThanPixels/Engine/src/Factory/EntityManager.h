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
	* \brief classe representant toutes les entit�s de la sc�ne.
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
	    * Au debut de la scene, genere toutes les entit�s disponibles.
	    */
		virtual void GenerateEntity(Scene* sc) = 0;
		/*!
		* \brief Met a jour toutes les entit�s
		*
		* Appel� au debut du gameloop, cette function permait de mette a jour toutes les entit�s de M_EntityToChange, dans M_EntityVector et M_EntityMap avant tout autre utilisation des entit�s.
		*/
		void Update();
		/*!
		* \brief Demande une entite libre
		*
		* \return une entite libre d utilisatation
		*/
		int RequestEntity(std::string tag);
		/*!
		* \brief Retourne les entit�s qui peuvent �tre dessin�es � l'�cran.
		*
		* \return un vecteur d'entit�
		*/
		std::vector<Engine::Entity*> EntityToDraw();
		/*!
		*  \brief Retourne les entit�s qui ont toutes un m�me components.
		*  \param name : Nom du components
		*  
		* \return un vector d'entite
		*/
		std::vector<Engine::Entity*> GetAllEntityWithComponent(std::string Component);
		/*!
		* \brief Retourne une entit� qui � l'ID du param�tre.
		* \param int id : id du components
		* \return une entite
		*/
		Engine::Entity* GetEntityWithId(int id);
		/*!
		* \brief Retoune true si il y a des entit�s dans la file d'attente.
		*
		* \return Bool�en
		*/
		bool AsEntityWaiting();
		/*!
		* \brief Ajoute une entite dans la liste d'attente.
		*
		* \param S_Delay_Entity entite : structure de l'entite
		*/
		void AddToWaiting(S_Delay_Entity entite);
		/*!
		* \brief Retourne les entit�s qui ont toutes un m�me tag.
		* \param name : Nom du tag
		* \return Un vecteur d'entit�.
		*/
		std::vector<Engine::Entity*> GetAllEntityWithTag(std::string Tag);
		/*!
		* \brief Fin de traitement de l'entit�.
		* \param Entity entity : entite
		* \param EntityState entitystate : states
		* Une fois l'entit� a fini dans la liste d'attente, lui faire des actions.
		*/

		virtual void EntityEndWaiting(Engine::Entity* entity, EntityState entitystate) = 0;

	private:
		/*!
		* \brief Appel de la fonction n�cessaire � la struct.
		* Prend struct par struct dans la waiting list et call la function qu elle a besoin entre les 4 disponibles
		*/
		void EntityWaitingListDispatch();
		/*!
		* \brief Flush le contenu d'une entit�.
		*
		* Si une entite dans M_EntityToChange, la variable "E_CanBeUsed" est differente alors appele cette function et la vide de ces components et change sont etat pour etre utilisable pour une autre entite
		*/
		Engine::Entity* RemoveEntity(S_Delay_Entity entite);
		/*
		* \brief Ajoute une entite � partir de la struct.
		*/
		Engine::Entity* AddEntity(S_Delay_Entity entite);
	};
}