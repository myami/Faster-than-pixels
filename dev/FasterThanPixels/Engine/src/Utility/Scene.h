#pragma once
#include "../Factory/EntityManager.h";
#include "../Utility/Action.h"
namespace Engine {
	class Scene {
	public:
		Scene();
		Scene(std::string name);
		std::unique_ptr<EntityManager> S_EntityManager;
		std::string S_Name;
		std::map<int, std::string> ActionScene; // chaque input du clavier et un nombre. le string represente le nom de l action lie a l input. par exemple dans un menu la touche W peux monter
		// dans un menu alors que dans le jeu il permait d aller de lavant
		bool S_Paused;
		bool S_End;
		virtual void S_Update() = 0; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4 ( delete , rajouter de quoi dans les vectors)
		virtual void S_Action() = 0; // Input recu 2/4 doit etre appeler dans S_Input du gamemanager
		virtual void S_Simulation() = 0; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
		virtual void S_Syteme() = 0; // tout les systeme de la scene ( tout les system lie au component) mais a jour les components de la simulation et des inputs
		virtual void S_Render() = 0; // fin de frame affiche le resultat de la simulation 4/4 la partie draw
		void RegisterAction(int key,std::string ActionName); // enregistre dans ActionScene les inputs disponibles pour la scene
		virtual void S_ActionTrigger(Action& action) = 0; // quand le joueur presse sur X le gamemanager va checker si dans ActionScene il y a une action sur se input et si oui lance l'action ici  (dans le S_action)
		// ces un switch qui a toutes les actions possibles de la scene 

	};
}