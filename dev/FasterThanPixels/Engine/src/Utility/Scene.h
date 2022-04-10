#pragma once
#include "SFML/Graphics.hpp"
#include "../Factory/EntityManager.h"
#include "InputAction.h"
#include "box2d/box2d.h"

	class SceneManager;
namespace Engine {
	/*! \class Path
	* \brief classe qui gere les chemins pour une IA par exemple
	*/
	class Scene {
	public:
		Scene();
		Scene(std::string name);
		EntityManager* S_EntityManager;  /*!< Sous syteme qui gere les entite */
		std::string S_Name;  /*!< Nom de la scene  */
		std::vector<Engine::InputAction> ActionScene;  /*!< Chaque input disponible dans la scene */
		SceneManager* _SceneManager;
		b2World* World;



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
		void S_Action(sf::Event event); 
		/*!
		*  \brief S_Simulation
		*
		*  Appeler dans la gameloop , Appelle la librairie Box2D et sont monde pour savoir ou deplacer les elements lie qui bouge avec la physique
		*/
		void S_Simulation(); 
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
		void RegisterAction(Engine::InputAction Action); 
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
		/*!
		*  \brief S_Input_Mouse
		*
		*  Appeler quand le joueur clique quelque part dans le jeu
		*/
		virtual void S_Input_Mouse(sf::Event event) = 0;
		/*!
		*  \brief S_Input_Text
		*
		*  Appeler quand le joueur ecrit du texte dans le jeu
		*/
		virtual void S_Input_Text(sf::Event event) = 0;
		
		std::vector<Engine::InputAction> GetKeyInput(Engine::Trigger inputype);


		virtual void S_Static_Physic(b2Body* body) = 0;
		virtual void S_Dynamic_Physic(b2Body* body) = 0;
		virtual void S_Kynematic_Physic(b2Body* body) = 0;

		
	};
}