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
		void Tick() override; // debut de frame met a jour tout se qu il doit mettre a jour 1 /4
		void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
		void S_ActionTrigger(std::string ActionName) override;
		void Begin_Play() override;
		void End_Play() override;
		void S_Input_Mouse(sf::Event event) override;
		void S_Input_Text(sf::Event event) override;
		void S_Static_Physic(b2Body* body) override;
		void S_Dynamic_Physic(b2Body* body) override;
		void S_Kynematic_Physic(b2Body* body) override;



	};
}
