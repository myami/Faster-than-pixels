#pragma once
#include "../Utility/Scene.h"
#include <vector>

namespace Engine {
class GameManager;
	/*! \class SceneManager
	* \brief classe representant les scenes dans le jeu
	*
	*/
	class SceneManager {
		std::vector <Scene*> M_Scene; /*!< Liste de toutes les scenes disponible */
	public:
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
		Scene& GetScene(std::string name);
		/*!
		*  \brief GetCurrentScene
		*
		*  Return la scene actuellement entrain de tourner
		* \return la scene actuelle
		*/
		Scene& GetCurrentScene();
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
		virtual void Init() =0;



	};
}