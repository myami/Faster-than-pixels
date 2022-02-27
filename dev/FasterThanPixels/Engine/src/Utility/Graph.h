#pragma once
#include <vector>
#include <string>
namespace Engine {

	class Graph_Gamemodes {
		std::vector<Graph_Gamemodes*> ConnectedGamemode; // tout les gamemodes auquel il est lie
	public:
		std::string NameGamemode; // nom du gamemode
		Graph_Gamemodes* GetRandomGamemode(); // return un mode de jeu random connecter a celui ci
		void AddGameMode(Graph_Gamemodes*); // ajoute un gamemode dans le vecteur

	};


}