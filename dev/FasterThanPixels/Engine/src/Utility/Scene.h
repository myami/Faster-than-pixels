#pragma once
#include "SFML/Graphics.hpp"
#include "../Factory/EntityManager.h"
#include "InputAction.h"
#include "box2d/box2d.h"
#include "StateMachine/State.h"

class SceneManager;
namespace Engine {
	/*! \class Scene
	* \brief classe qui le fonctionnement d'une scène.
	*/
	class Scene : public Engine::FSM_State {
	public:
		Scene();
		Scene(std::string name);
		EntityManager* S_EntityManager;  /*!< Sous syteme qui gere les entite */
		std::vector<Engine::InputAction> ActionScene;  /*!< Chaque input disponible dans la scene */
		SceneManager* _SceneManager; /*!< sceneManager */
		b2World* World; /*!< Monde box2d */
		const int SCALE = 30; /*!< Scale de box2d */

		bool S_Paused; /*!< Si la scene est en pause */
		bool S_End; /*!< Si la scene est fini d'etre utiliser */
		/*!
		* @def S_Simulation
		*
		* Appelé dans la gameloop pour appeler les sous-fonctions de Box2D
		*/
		void S_Simulation();
		/*!
		* @def  S_Action
		*
		* Appeler dans la gameloop pour ajouter les inputs recus par les events de sfml(mouvement, tir ,....)
		*/
		void S_Action(sf::Event event);
		/*!
		* @def  S_Render
		*
		* Appeler a la fin de la gameloop, permait d'afficher les elements dans la scene a la fin de la gameloop
		*/
		virtual void S_Render() = 0;
		/*!
		* @def  RegisterAction
		*
		* Enregistre dans la scene les inputs disponible
		* \param key : represente la touche a appuyer
		* \param ActionName : Nom de l'action lie a la touches
		*/
		void RegisterAction(Engine::InputAction Action);
		/*!
		* @def S_ActionTrigger
		*
		* Verifie que l'input que le joueur appuye existe
		* \param ActionName : Nom de l'action lie a la touches
		*/
		virtual void S_ActionTrigger(std::string ActionName) = 0;

		/*!
		* @def S_Input_Mouse
		*
		* Appelé quand le joueur clique quelque part dans le jeu
		*/
		virtual void S_Input_Mouse(sf::Event event) = 0;
		/*!
		* @def S_Input_Text
		*
		* Appelé quand le joueur ecrit du texte dans le jeu
		*/
		virtual void S_Input_Text(sf::Event event) = 0;

		std::vector<Engine::InputAction> GetKeyInput(Engine::Trigger inputype);
		/*!
		* @def S_Static_Physic
		*
		* Appelé pour tout les elements statics de box2d
		*/
		virtual void S_Static_Physic(b2Body* body) = 0;
		/*!
		*  @def S_Dynamic_Physic
		*
		*  Appelé pour tout les elements dynamic de box2d
		*/
		virtual void S_Dynamic_Physic(b2Body* body) = 0;
		/*!
		*  @def S_Kynematic_Physic
		*
		*  Appelé pour tout les elements kynematic de box2d
		*/
		virtual void S_Kynematic_Physic(b2Body* body) = 0;
	};
}