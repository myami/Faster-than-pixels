#include "Game.h"
#include "../Factory/FTP_SceneManager.h"
#include <sstream>
#include "../ECS/Components/C_Animated_Render.h"
#include "../ECS/Components/C_Static_Collider_Sphere.h"
#include "../ECS/Components/C_Transform.h"
#include "../ECS/Components/C_Static_Render.h"
#include "../ECS/Components/C_Kynematic_Collider_Sphere.h"
#include "../ECS/Components/C_Transform.h"
#include "../ECS/Components/C_Mouvement_Actif.h"
#include "../ECS/System/S_MouvementActif.h"


Game::Game(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;

}

void Game::S_Syteme()
{
}

void Game::S_Update()
{
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(*_SceneManager->_GameManager->Windows);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);
	MousePosView = _SceneManager->_GameManager->Windows->mapPixelToCoords(MousePosWindow);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	std::stringstream ss;
	ss << " Coord \n X : " << MousePosView.x << "\n Y : " << MousePosView.y << "\n";

	text.setString(ss.str());
	for (size_t i = 0; i < S_EntityManager->GetAllEntityWithComponent("Render").size(); i++)
	{
		C_Animated_Render* CheckAnimatation = dynamic_cast<C_Animated_Render*>(S_EntityManager->GetAllEntityWithComponent("Render")[i]->GetComponent("Render"));
		if (CheckAnimatation) {
			CheckAnimatation->AnimatedSprite.updateSprites(_SceneManager->_GameManager->DeltaTime); // mais a jour le sprite des animations
		}
	}
	for (size_t i = 0; i < S_EntityManager->GetAllEntityWithComponent("Mouvement").size(); i++) 
	{
		C_MouvementActif* CheckMovement = dynamic_cast<C_MouvementActif*>(S_EntityManager->GetAllEntityWithComponent("Mouvement")[i]->GetComponent("Mouvement"));

		if (CheckMovement) {

			C_Static_Render* Static = dynamic_cast<C_Static_Render*>(S_EntityManager->GetAllEntityWithComponent("Mouvement")[i]->GetComponent("Render"));
			C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(S_EntityManager->GetAllEntityWithComponent("Mouvement")[i]->GetComponent("Transform"));

			//Static->Sprite.move(sf::Vector2f(PlayerTransform->Direction * _SceneManager->_GameManager->DeltaTime ));
			//std::cout << "Position : X : " << Static->Sprite.getPosition().x << " Y : " << Static->Sprite.getPosition().y << " DT : " << _SceneManager->_GameManager->DeltaTime << std::endl;

			System_Mouvement_Actif->RunSystem(S_EntityManager->GetAllEntityWithComponent("Mouvement")[i], _SceneManager->_GameManager->DeltaTime);
		}

	}


}

void Game::S_Render()
{
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);

	// render game


	std::vector<Engine::Entity*> EntityToDraw = S_EntityManager->EntityToDraw();
	for (size_t i = 0; i < EntityToDraw.size(); i++)
	{
		if (EntityToDraw[i]->E_IsAnimated) {
			C_Animated_Render* CheckAnimatation = dynamic_cast<C_Animated_Render*>(EntityToDraw[i]->GetComponent("Render"));
			_SceneManager->_GameManager->Windows->draw(CheckAnimatation->AnimatedSprite.FrameToDraw());

		}
		else {
			C_Static_Render* Static = dynamic_cast<C_Static_Render*>(EntityToDraw[i]->GetComponent("Render"));
				_SceneManager->_GameManager->Windows->draw(Static->Sprite);

	
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
	C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(S_EntityManager->M_EntityMap["Player"][0]->GetComponent("Transform"));

	if (ActionName == "Forward") {
		_SceneManager->_GameManager->View.move(0.f,-viewspeed * _SceneManager->_GameManager->DeltaTime );
		PlayerTransform->Direction = sf::Vector2f(0, -viewspeed);
	}
	if (ActionName == "Backward") {
		_SceneManager->_GameManager->View.move(0.f, viewspeed * _SceneManager->_GameManager->DeltaTime );
		PlayerTransform->Direction = sf::Vector2f(0, viewspeed);

	}
	if (ActionName == "Left") {
		_SceneManager->_GameManager->View.move( -viewspeed * _SceneManager->_GameManager->DeltaTime ,0.f);
		PlayerTransform->Direction = sf::Vector2f(-viewspeed,0);

	}
	if (ActionName == "Right") {
		_SceneManager->_GameManager->View.move( viewspeed * _SceneManager->_GameManager->DeltaTime , 0.f);
		PlayerTransform->Direction = sf::Vector2f(viewspeed, 0);

	}



}

void Game::S_Begin_Play()
{
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	text.setCharacterSize(30);
	text.setPosition(20.f, 20.f);
	text.setString("Coord");





	S_EntityManager->M_TotalEntity = 500; // on veux 500 entite dans le jeu
	S_EntityManager->GenerateEntity();

	Engine::InitEnvironnement(seed,S_EntityManager);
	InitPlanet();
	InitAsteroid();


	RegisterAction(sf::Keyboard::W, "Forward");
	RegisterAction(sf::Keyboard::S, "Backward");
	RegisterAction(sf::Keyboard::A, "Left");
	RegisterAction(sf::Keyboard::D, "Right");

	Gravity = b2Vec2(0, 0);
	World = new b2World(Gravity);
	System_Mouvement_Actif = new S_Mouvement_Actif();
	InitPlayer();

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

		C_Animated_Render* PlanetRender = dynamic_cast<C_Animated_Render*>(S_EntityManager->M_EntityMap["Planet"][i]->GetComponent("Render"));
		srand(seed  + i );
		int randomplanet = rand() % AvailablePlanet.size() + 0;
		std::cout << randomplanet;
		PlanetRender->AnimatedSprite.SetupAnimation(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailablePlanet[randomplanet]), 15 / 60.f, {10,1}, sf::Vector2f(0.f, 0.f));
		float randomx = rand() % (int)MapSize.x + -MapSize.x;
		float randomy = rand() % (int)MapSize.y + -MapSize.y;

		PlanetRender->AnimatedSprite.MoveSprite(sf::Vector2f(randomx, randomy));

	}
}


void Game::InitAsteroid()
{
	AvailableAsteroid.push_back("Asteroid0");
	AvailableAsteroid.push_back("Asteroid1");
	AvailableAsteroid.push_back("Asteroid2");
	AvailableAsteroid.push_back("Asteroid3");
	AvailableAsteroid.push_back("Asteroid4");
	AvailableAsteroid.push_back("Asteroid5");
	AvailableAsteroid.push_back("Asteroid6");
	AvailableAsteroid.push_back("Asteroid7");
	AvailableAsteroid.push_back("Asteroid8");
	AvailableAsteroid.push_back("Asteroid9");
	AvailableAsteroid.push_back("Asteroid10");
	AvailableAsteroid.push_back("Asteroid11");
	AvailableAsteroid.push_back("Asteroid12");
	

	
	
	
	for (size_t i = 0; i < S_EntityManager->M_EntityMap["Asteroid"].size(); i++) 
	{
		
		S_EntityManager->M_EntityMap["Asteroid"][i]->AddComponent("Render", new C_Static_Render());
		S_EntityManager->M_EntityMap["Asteroid"][i]->AddComponent("Collider", new C_Static_Collider_Sphere());
		
		C_Static_Render* AsteroidRender = dynamic_cast<C_Static_Render*>(S_EntityManager->M_EntityMap["Asteroid"][i]->GetComponent("Render"));
		srand(seed / 2 + i);
		int randomasteroid = rand() % AvailableAsteroid.size() + 0;
		float randomx = rand() % (int)MapSize.x + -MapSize.x;
		float randomy = rand() % (int)MapSize.y + -MapSize.y;
		float randomscale = rand() % 1 + 0.3;
		AsteroidRender->Sprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailableAsteroid[randomasteroid]));
		AsteroidRender->Sprite.setOrigin(AsteroidRender->Sprite.getGlobalBounds().width / 2.f, AsteroidRender->Sprite.getGlobalBounds().height / 2.f);
		AsteroidRender->Sprite.setScale(sf::Vector2f(randomscale, randomscale));
		AsteroidRender->Sprite.setPosition(_SceneManager->_GameManager->View.getCenter());
		AsteroidRender->Sprite.move(sf::Vector2f(randomx, randomy));

	}







}

void Game::InitPlayer()
{
	Engine::Entity* Player = S_EntityManager->RequestEntity();
	Player->E_CanBeUsed = false;
	Player->E_Tag = "Player";
	Player->E_IsAnimated = false;
	S_EntityManager->EntityChangeMap(Player, "Empty", "Player");
	Player->AddComponent("Render", new C_Static_Render());
	Player->AddComponent("Collider", new C_Kynematic_Collider_Sphere());
	Player->AddComponent("Transform", new C_Transform());
	Player->AddComponent("Mouvement", new C_MouvementActif());

	C_Static_Render* Render = dynamic_cast<C_Static_Render*>(Player->GetComponent("Render"));

	Render->Sprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"));
	Render->Sprite.setScale(sf::Vector2f(.2f, .2f));
	Render->Sprite.setOrigin(Render->Sprite.getGlobalBounds().width / 2.f, Render->Sprite.getGlobalBounds().height / 2.f);
	Render->Sprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	std::cout <<"Default X : " << _SceneManager->_GameManager->View.getCenter().x << " Y : " <<_SceneManager->_GameManager->View.getCenter().y << std::endl;



}
