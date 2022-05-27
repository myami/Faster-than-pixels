#pragma once

#include "SFML/Graphics.hpp"
namespace Engine {
	class AssetManager;
	class SceneManager;
	/**
	 * @def View_Height
	 * @brief Hauteur par defaut de la fenêtre.
	*/
	static const float View_Height = 1080.f;
	/**
	 * @def View_Width
	 * @brief Largeur par defaut de la fenêtre.
	*/
	static const float View_Width = 1920.f;
	/*! \class GameManager
	* \brief Classe représentant le jeu, elle contient tout les sous-systèmes et gère la gameloop.
	*
	*/
	class GameManager {
		sf::Clock ClockDeltaTime;
	public:
		AssetManager* G_AssetManager; /*!< Sous-systeme qui gere les assets */
		SceneManager* G_SceneManager;/*!< Sous-systeme qui gere les scenes */
		sf::RenderWindow* Windows; /*!< La fenetre */
		sf::View View; /*!< La vue dans la fenetre(camera ) */
		bool Running; /*!< Si le programme tourne */
		float DeltaTime = 0.f; /*!< deltatime */
		/*!
		* \brief Quit
		*
		* Quitte le jeu
		*/
		void Quit();
		/*!
		* \brief Initialisation
		*
		* Initialise les sous-systemes pour avoir toutes les données nécessaires pour que le jeu fonctionne.
		* \param NameOfTheGame : Nom du jeu
		* \param FirstScene : Nom de la premiere scene a lancer
		*/
		virtual void Game_Init(std::string NameOfTheGame, std::string FirstScene) = 0;
		/*!
		* \brief GameLoop
		*
		* La loop du jeux, elle est appelée à chaque frame pour mettre à jour le contenu du jeu.
		*/
		void GameLoop();
		/*!
		*  \brief S_Input
		*
		*  Gère les events de SFML pour recevoir les inputs, cette fonction se trouve dans la gameloop.
		*/
		void S_Input();
		/*!
		*  \brief Redimension de la vue.
		*
		*  Scale proprement les éléments dans la fenetre de jeu quand elle change de taille
		* \param event : event de sfml
		*/
		void ResizeView(sf::Event event);
	};
}