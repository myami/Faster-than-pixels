#include "Scene.h"
#include "StateMachine/State.h"

void Engine::Scene::RegisterAction(Engine::InputAction Action)
{
	ActionScene.push_back(Action);
}

std::vector<Engine::InputAction> Engine::Scene::GetKeyInput(Engine::Trigger inputype)
{
	std::vector<Engine::InputAction> key;
	for (const auto& action : ActionScene)
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

Engine::Scene::Scene(std::string name):Engine::FSM_State()
{
	param.StateName = name;
}

void Engine::Scene::S_Action(sf::Event event)
{
	if (event.type == event.KeyPressed)
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

void Engine::Scene::S_Simulation()
{
	if (World != nullptr) {
		World->Step(1 / 60.f, 8, 3);
		for (b2Body*  BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{
			if (BodyIterator->GetType() == b2_dynamicBody)
			{
				if (S_EntityManager->GetEntityWithId(S_EntityManager->M_PhysicMap[BodyIterator]) != nullptr)
				{
					S_Dynamic_Physic(BodyIterator);
				}
			}
			else if (BodyIterator->GetType() == b2_staticBody)
			{
				if (S_EntityManager->GetEntityWithId(S_EntityManager->M_PhysicMap[BodyIterator]) != nullptr)
				{
					S_Static_Physic(BodyIterator);
				}
			}
			else if (BodyIterator->GetType() == b2_kinematicBody)
			{
				if (S_EntityManager->GetEntityWithId(S_EntityManager->M_PhysicMap[BodyIterator]) != nullptr)
				{
					S_Kynematic_Physic(BodyIterator);
				}
			}
		}
	}
}