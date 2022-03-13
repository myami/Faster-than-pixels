#include "Scene.h"

void Engine::Scene::RegisterAction(int key, std::string ActionName)
{

	ActionScene.insert({key,ActionName });
}

Engine::Scene::Scene()
{

}

Engine::Scene::Scene(std::string name)
{
	this->S_Name = name;
	S_EntityManager = new EntityManager();

}

void Engine::Scene::S_Action(sf::Event event)
{
	if (event.KeyPressed) {
		for (const auto& action : ActionScene) {
			sf::Keyboard::Key val = static_cast<sf::Keyboard::Key>(action.first);
			if (event.key.code == val && sf::Keyboard::isKeyPressed(val))
				S_ActionTrigger(action.second);

		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			S_Input_Mouse(event);
		}
	}
	else if (event.type == sf::Event::TextEntered) {
		S_Input_Text(event);
	}
}
