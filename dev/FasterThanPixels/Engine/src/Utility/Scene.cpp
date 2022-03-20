#include "Scene.h"

void Engine::Scene::RegisterAction(Engine::InputAction Action)
{

	ActionScene.push_back(Action);
}

std::vector<Engine::InputAction> Engine::Scene::GetKeyInput(Engine::Trigger inputype)
{
	std::vector<Engine::InputAction> key;
	for (const auto & action : ActionScene)
	{
		if (action.TriggerEvent == inputype) {
			key.push_back(action);
		}
	}
	return key;
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
	if ( event.type == event.KeyPressed)
	{
		auto keydown = GetKeyInput(Engine::Trigger::KeyDown);
		for (const auto& action : keydown)
		{
			InputAction in = action;

			sf::Keyboard::Key val = static_cast<sf::Keyboard::Key>(in.Keycode);

			if (event.key.code == val) {
				S_ActionTrigger(action.Name);

			} 
		}
	}

	if (event.type == event.KeyReleased) {

		auto keydown = GetKeyInput(Engine::Trigger::KeyUp);
		for (const auto& action : keydown)
		{
			InputAction in = action;

			sf::Keyboard::Key val = static_cast<sf::Keyboard::Key>(in.Keycode);

			if (event.key.code == val) {
				S_ActionTrigger(action.Name);

			}
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
