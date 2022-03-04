#pragma once
#include "../Factory/EntityManager.h";
#include "SFML/Graphics.hpp"

namespace Engine {
	/*! \class Path
	* \brief classe qui gere les chemins pour une IA par exemple
	*/
	class Scene {
	public:
		Scene();
		Scene(std::string name);
		std::unique_ptr<EntityManager> S_EntityManager;  /*!< Sous syteme qui gere les entite */
		std::string S_Name;  /*!< Nom de la scene  */
		std::map<int, std::string> ActionScene;  /*!< Chaque input disponible dans la scene */
		bool S_Paused; /*!< Si la scene est en pause */
		bool S_End; /*!< Si la scene est fini d'etre utiliser */
			/*!
			*  \brief S_Update
			*
			*  Appeler au debut de la gameloop, Cette function call dans l'entityManager pour mettre a jour sont contenu
			*/
		virtual void S_Update() = 0; 
		/*!
		*  \brief S_Action
		*
		*  Appeler dans la gameloop pour ajouter les inputs recus par les events de sfml(mouvement, tir ,....)
		*/
		virtual void S_Action(sf::Event event) = 0; 
		/*!
		*  \brief S_Simulation
		*
		*  Appeler dans la gameloop , Appelle la librairie Box2D et sont monde pour savoir ou deplacer les elements lie qui bouge avec la physique
		*/
		virtual void S_Simulation() = 0; 
		/*!
		*  \brief S_Syteme
		*
		*  Appeler dans la gameloop , Certain Component on des systemes qui permette de calculer une position, un mouvement ou autre baser sur des inputs (input joueur et simulation)
		*/
		virtual void S_Syteme() = 0;
		/*!
		*  \brief S_Render
		*
		*  Appeler a la fin de la gameloop, permait d'afficher les elements dans la scene a la fin de la gameloop
		*/
		virtual void S_Render() = 0; 
		/*!
		*  \brief RegisterAction
		*
		*  Enregistre dans la scene les inputs disponible
		* \param key : represente la touche a appuyer 
		* \param ActionName : Nom de l'action lie a la touches
		*/
		void RegisterAction(int key,std::string ActionName); 
		/*!
		*  \brief S_ActionTrigger
		*
		*  Verifie que l'input que le joueur appuye existe 
		* \param ActionName : Nom de l'action lie a la touches
		*/
		virtual void S_ActionTrigger(std::string ActionName) = 0; 
		/*!
		*  \brief S_Begin_Play
		*
		*  Appeler au lancement de la scene apres un changement de scene
		*/
		virtual void S_Begin_Play() = 0;
		/*!
		*  \brief S_End_Scene
		*
		*  Appeler a la fin de la scene juste avant un changement de scene
		*/
		virtual void S_End_Scene() = 0; 
		
	};
}