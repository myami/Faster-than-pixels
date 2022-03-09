#pragma once

#include "Scene.h"
class SceneManager;
/*! \class Game
* \brief classe enfant de Scene, represente le niveau ou le joueur joue
*
*/
namespace Engine {
	class BlankScene : public Engine::Scene {
	public:
		BlankScene(std::string name);
		void S_Syteme() override; // tout les systeme de la scene ( tout les system lie au component)
		void S_Update() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
		void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
		void S_Simulation() override; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
		void S_ActionTrigger(std::string ActionName) override;
		void S_Begin_Play() override;
		void S_End_Scene() override;
		void S_Input_Mouse(sf::Event event) override;
		void S_Input_Text(sf::Event event) override;



	};
}
