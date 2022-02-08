#pragma once
#include "../Factory/EntityManager.h";
namespace Engine {
	class Scene {
		EntityManager S_EntityManager;
		std::string S_Name;
		bool S_Paused;
		bool S_End;
		virtual void S_Update() = 0; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
		virtual void S_Render() = 0; // fin de frame affiche le resultat de la simulation 4/4
		virtual void S_Action() = 0; // Input recu 2/4
		virtual void S_Simulation() = 0; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
		// je sais pas si avec box2D ces un bonne ordre et une bonne maniere de bouger d abord avec les inputs, puis run la simulation, peux t on envoyer la nouvelle position du joueur
		// dans la simulation box2d avant qu on le fasse avancer de step ?
	};
}