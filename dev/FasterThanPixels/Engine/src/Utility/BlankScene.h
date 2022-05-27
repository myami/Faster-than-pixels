#pragma once

#include "Scene.h"
class SceneManager;
/*! \class BlankScene
* \brief classe enfant de Scene, represente le niveau ou le joueur joue
*
*/
namespace Engine {
	class BlankScene : public Engine::Scene {
	public:
		BlankScene(std::string name);
		void Tick() override;
		void S_Render() override;
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
