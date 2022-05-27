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
	class SceneManager : public FiniteStateMachine {
	public:
		/*!
		* \brief Reset
		*
		* Reset la statemachine.
		*/
		void Reset_FSM();
		/*!
		* \brief Run
		*
		* Fait marcher la statemachine;
		*/
		bool Run_FSM();
		/*!
		* \brief Constructeur
		*
		* Constructeur sans argument.
		*/
		SceneManager();
		/*!
		* \brief Constructeur avec arguments.
		*
		* Constructeur avec argument pour passer son parent.
		* \param gm : parent
		*/
		SceneManager(Engine::GameManager* gm);

		Engine::GameManager* _GameManager; /*!< Reference à son parent le GameManager */
		/*!
		* \brief GetScene
		*
		* Retourne la scene selectionnée.
		* \param name : Nom de la scene
		* \return la scene selectionner
		*/
		Scene* GetScene(std::string name);
		/*!
		* \brief GetCurrentScene
		*
		* Retourne la sceèe active.
		* \return la scene actuelle
		*/
		Scene* GetCurrentScene();
		/*!
		* \brief AddScene
		*
		* Ajoute une scène dans le manager
		* \param scene : scene a ajouter
		*/
		void AddScene(Scene* scene);
		/*!
		* \brief Initialisation.
		*
		* Initialise le scene_manager, il charge toutes les scenes disponibles dans la listes
		*/
		virtual void Init(std::string FirstScene) = 0;
		/*!
		*  \brief Change de niveau
		*
		* \param newscene : Nom du niveaux à charger
		*/
		void ChangeScene(std::string newscene);

		~SceneManager();
		/*!
		* \brief GetStatesFromScene
		*
		* return le FSM_State de la scene
		* \param Scene sc : le niveaux
		*/
		FSM_State* GetStatesFromScene(Scene* sc);
	};
}