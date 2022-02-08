#pragma once
#include "AssetManager.h"
#include "SceneManager.h"
namespace Engine {
	class GameManager {
		AssetManager G_AssetManager;
		SceneManager G_SceneManager;
		virtual void Game_Init() = 0; // initialiser toutes les donnes du jeu
		virtual void GameLoop() = 0;// loop principale du jeu
	};
}