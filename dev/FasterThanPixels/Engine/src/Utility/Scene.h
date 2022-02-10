#pragma once
#include "../Factory/EntityManager.h";
#include "../Utility/Action.h"
namespace Engine {
	class Scene {
		EntityManager S_EntityManager;
		std::string S_Name;
		std::map<int, std::string> ActionScene; // chaque input du clavier et un nombre. le string represente le nom de l action lie a l input. par exemple dans un menu la touche W peux monter
		// dans un menu alors que dans le jeu il permait d aller de lavant
		bool S_Paused;
		bool S_End;
	
		virtual void S_Syteme() = 0; // tout les systeme de la scene ( tout les system lie au component)
		virtual void S_Update() = 0; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
		virtual void S_Render() = 0; // fin de frame affiche le resultat de la simulation 4/4
		virtual void S_Action() = 0; // Input recu 2/4
		virtual void S_Simulation() = 0; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
		// je sais pas si avec box2D ces un bonne ordre et une bonne maniere de bouger d abord avec les inputs, puis run la simulation, peux t on envoyer la nouvelle position du joueur
		// dans la simulation box2d avant qu on le fasse avancer de step ?
		void RegisterAction(int key,std::string ActionName); // enregistre dans ActionScene les inputs disponibles pour la scene
		virtual void S_Action(Action& action); // quand le joueur presse sur X le gamemanager va checker si dans ActionScene il y a une action sur se input et si oui lance l'action ici 


	};
}