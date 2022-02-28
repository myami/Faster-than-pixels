#pragma once

#include "SFML/Graphics.hpp"
namespace Engine {
class AssetManager;
class SceneManager;
	/**
	 * @def View_Height
	 * @brief Hauteur par default de la fenetre
	*/
	static const float View_Height = 1080.f;
	/**
	 * @def View_Width
	 * @brief Largeur par default de la fenetre
	*/
	static const float View_Width = 1920.f;
	/*! \class GameManager
	* \brief classe representant le jeu, il contient tout les sous-systeme et a la gameloop
	*
	*/
	class GameManager {
	public:
		std::unique_ptr<AssetManager> G_AssetManager; /*!< Sous-systeme qui gere les assets */
		std::unique_ptr<SceneManager> G_SceneManager;/*!< Sous-systeme qui gere les scenes */
		sf::RenderWindow* Windows; /*!< La fenetre */
		sf::View View; /*!< La vue dans la fenetre(camera ) */
		std::string CurrentScene; /*!< La scene actuelle */
		bool Running; /*!< Si le programme tourne */
		 /*!
		 *  \brief Quit
		 *
		 *  Quitte le jeu
		 */
		virtual void Quit() = 0;
		/*!
		*  \brief Game_Init
		*
		*  Initialise les sous-systemes pour avoir toutes les donneer necessaires pour que le jeu marche
		*/
		virtual void Game_Init() = 0; // initialiser toutes les donnes du jeu
		/*!
		*  \brief GameLoop
		*
		*  La loop du jeux, elle est appeler a chaque frame pour mettre a jour le contenu du jeu
		*/
		virtual void GameLoop() = 0;// loop principale du jeu
		/*!
		*  \brief S_Input
		*
		*  Gere les events de SFML pour recevoir les inputs, cette function se trouve dans la gameloop
		*/
		virtual void S_Input() = 0; 
		/*!
		*  \brief ResizeView
		*
		*  Scale proprement les elements dans la fenetre de jeu quand elle change de taille
		* \param event : event de sfml
		*/
		void ResizeView(sf::Event event);
		/*!
		*  \brief ChangeScene
		*
		*  Change de niveaux
		* \param newscene : Nom niveaux a charger
		*/
		void ChangeScene(std::string newscene);


	};
}