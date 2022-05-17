#pragma once
#include <vector>
#include <string>
#include "../Utility/StateMachine/FiniteStateMachine.h"

namespace Engine {
	class GameManager;
	class FSM_State;
	class Scene;
	/*! \class SceneManager
	* \brief classe representant les scenes dans le jeu
	*
	*/
	class SceneManager : public FiniteStateMachine{
	public:
		void Reset_FSM();
		bool Run_FSM();
		/*!
		*  \brief SceneManager
		*
		*  Constructeur sans argument
		*/
		SceneManager();
		/*!
		*  \brief SceneManager
		*
		*  Constructeur avec argument pour passer sont parent
		* \param gm : parent
		*/
		SceneManager(Engine::GameManager* gm);

		Engine::GameManager* _GameManager; /*!< Reference a sont parent le GameManager */
		/*!
		*  \brief GetScene
		*
		*  Return la scene selectionner
		* \param name : Nom de la scene
		* \return la scene selectionner
		*/
		Scene* GetScene(std::string name);
		/*!
		*  \brief GetCurrentScene
		*
		*  Return la scene actuellement entrain de tourner
		* \return la scene actuelle
		*/
		Scene* GetCurrentScene();
		/*!
		*  \brief AddScene
		*
		*  Ajoute une scene dans le manager
		* \param scene : scene a ajouter
		*/
		void AddScene(Scene* scene);
		/*!
		*  \brief Init
		*
		*  Initialise le scene_manager, il charge toutes les scenes disponibles dans la listes
		*
		*/
		virtual void Init(std::string FirstScene) = 0;
		/*!
		*  \brief ChangeScene
		*
		*  Change de niveaux
		* \param newscene : Nom niveaux a charger
		*/
		void ChangeScene(std::string newscene);

		~SceneManager();

		FSM_State* GetStatesFromScene(Scene* sc);

	};
}