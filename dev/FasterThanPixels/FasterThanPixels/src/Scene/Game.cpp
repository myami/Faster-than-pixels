#include "Game.h"
#include "../Factory/FTP_SceneManager.h"
#include <sstream>
#include "../ECS/Components/C_Animated_Render.h"
#include "../ECS/Components/C_Static_Collider_Sphere.h"
#include "../ECS/Components/C_Transform.h"
#include "../ECS/Components/C_Static_Render.h"



Game::Game(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
	RegisterAction(sf::Keyboard::W, "Forward");
	RegisterAction(sf::Keyboard::S, "Backward");
	RegisterAction(sf::Keyboard::A, "Left");
	RegisterAction(sf::Keyboard::D, "Right");




}

void Game::S_Syteme()
{
}

void Game::S_Update()
{
	dt = cloackdt.restart().asSeconds();
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(*_SceneManager->_GameManager->Windows);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);
	MousePosView = _SceneManager->_GameManager->Windows->mapPixelToCoords(MousePosWindow);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	std::stringstream ss;
	ss << "Screen : " << MousePosScreen.x << " " << MousePosScreen.y << "\n"
		<< " Windows : " << MousePosWindow.x << " " << MousePosWindow.y << "\n"
		<< " View : " << MousePosView.x << " " << MousePosView.y << "\n";

	text.setString(ss.str());
	for (size_t i = 0; i < S_EntityManager->GetAllEntityWithComponent("Render").size(); i++)
	{
		C_Animated_Render* CheckAnimatation = (C_Animated_Render*)S_EntityManager->GetAllEntityWithComponent("Render")[i]->GetComponent("Render");
		if (CheckAnimatation != nullptr) {
			CheckAnimatation->AnimatedSprite.updateSprites(dt); // mais a jour le sprite des animations
		}
	}
}

void Game::S_Render()
{
	_SceneManager->_GameManager->Windows->clear();
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);

	// render game
	_SceneManager->_GameManager->Windows->draw(shape);


	std::vector<Engine::Entity*> EntityToDraw = S_EntityManager->EntityToDraw();
	std::cout << EntityToDraw[11]->E_Id << std::endl;
	for (size_t i = 0; i < EntityToDraw.size(); i++)
	{
		C_Animated_Render* CheckAnimatation = (C_Animated_Render*)EntityToDraw[i]->GetComponent("Render");
		if (CheckAnimatation != nullptr) {
			_SceneManager->_GameManager->Windows->draw(CheckAnimatation->AnimatedSprite.FrameToDraw());

		}
		else {
			C_Static_Render* Static = (C_Static_Render*)EntityToDraw[i]->GetComponent("Render");
			if (Static != nullptr) {
				_SceneManager->_GameManager->Windows->draw(Static->Sprite);
			}
			else {
				std::cout << "L'entite n'a rien a render" << EntityToDraw[i]->E_Id << std::endl;
			}


		}
	
	}

	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	// render ui
	_SceneManager->_GameManager->Windows->draw(text);


}

void Game::S_Simulation()
{
}

void Game::S_ActionTrigger(std::string ActionName)
{
	if (ActionName == "Forward") {
		_SceneManager->_GameManager->View.move(0.f,-viewspeed * dt * 100);
	}
	if (ActionName == "Backward") {
		_SceneManager->_GameManager->View.move(0.f, viewspeed * dt * 100);
	}
	if (ActionName == "Left") {
		_SceneManager->_GameManager->View.move( -viewspeed * dt * 100,0.f);
	}
	if (ActionName == "Right") {
		_SceneManager->_GameManager->View.move( viewspeed * dt * 100,0.f);
	}
}

void Game::S_Begin_Play()
{
	shape.setSize(sf::Vector2f(100.f, 100.f));
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	text.setCharacterSize(30);
	text.setPosition(20.f, 20.f);
	text.setString("TEST");



	S_EntityManager->M_TotalEntity = 500; // on veux 500 entite dans le jeu
	S_EntityManager->GenerateEntity();

	Engine::InitEnvironnement(525615,S_EntityManager);
	InitPlanet();
}



void Game::S_Input_Mouse(sf::Event event)
{
}

void Game::S_Input_Text(sf::Event event)
{
}

void Game::InitPlanet()
{
	
	AvailablePlanet.push_back("BlackHole");
	AvailablePlanet.push_back("DryPlanet");
	AvailablePlanet.push_back("GazPlanet");
	AvailablePlanet.push_back("GazPlanet2");
	AvailablePlanet.push_back("IcePlanet");
	AvailablePlanet.push_back("IslandPlanet");
	AvailablePlanet.push_back("LavaPlanet");
	AvailablePlanet.push_back("MoonPlanet");
	AvailablePlanet.push_back("StarPlanet");
	AvailablePlanet.push_back("WetPlanet");
	
	
	


	for (size_t i = 0; i < S_EntityManager->M_EntityMap["Planet"].size(); i++)
	{
		S_EntityManager->M_EntityMap["Planet"][i]->AddComponent("Render", new C_Animated_Render());
		S_EntityManager->M_EntityMap["Planet"][i]->AddComponent("Collider", new C_Static_Collider_Sphere());

		C_Animated_Render* test = (C_Animated_Render*)S_EntityManager->M_EntityMap["Planet"][i]->GetComponent("Render");
		int randomplanet = rand() % AvailablePlanet.size() + 0;
		test->AnimatedSprite.SetupAnimation(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailablePlanet[randomplanet]), 15 / 60.f, {10,1}, sf::Vector2f(0.f, 0.f));
		float randomx = rand() % 3000 + -3000;
		float randomy = rand() % 3000 + -3000;

		test->AnimatedSprite.MoveSprite(sf::Vector2f(randomx, randomy));

	}
}
