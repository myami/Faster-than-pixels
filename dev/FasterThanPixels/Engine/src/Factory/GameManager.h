#pragma once
#include "AssetManager.h"
#include "SceneManager.h"
#include "SFML/Graphics.hpp"
namespace Engine {
	class GameManager {
	public:
		std::unique_ptr<AssetManager> G_AssetManager;
		std::unique_ptr<SceneManager> G_SceneManager;
		sf::RenderWindow* Windows;
		std::string CurrentScene;
		bool Running;
		virtual void Quit() = 0;
		virtual void Game_Init() = 0; // initialiser toutes les donnes du jeu
		virtual void GameLoop() = 0;// loop principale du jeu
		virtual void S_Input() = 0; // gerer les events de sfml (input) se trouve dans GameLoop
	};
}