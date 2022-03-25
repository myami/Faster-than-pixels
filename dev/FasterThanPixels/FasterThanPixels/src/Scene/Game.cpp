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
#include <map>


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

	UpdateEntity();

}

void Game::S_Render()
{
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);


	// render game


	auto EntityToDraw = S_EntityManager->EntityToDraw();
	for (auto Entity : EntityToDraw)
	{
		if (Entity->E_IsAnimated) {
			C_Animated_Render* CheckAnimatation = dynamic_cast<C_Animated_Render*>(Entity->GetComponent("Render"));
			_SceneManager->_GameManager->Windows->draw(CheckAnimatation->AnimatedSprite.FrameToDraw());
		}
		else {
			C_Static_Render* Static = dynamic_cast<C_Static_Render*>(Entity->GetComponent("Render"));
				_SceneManager->_GameManager->Windows->draw(Static->Sprite);
		}
	
	}

	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	// render ui
	_SceneManager->_GameManager->Windows->draw(text);

	// center UI on player





}



void Game::S_Simulation()
{
	World->Step(1 / 60.f, 8, 3);
	for (b2Body* BodyIterator = World->GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext()) 
	{
		if (BodyIterator->GetType() == b2_dynamicBody) 
		{
			if (S_EntityManager->M_PhysicMap[BodyIterator] != nullptr)
			{
				Engine::Entity* entity = S_EntityManager->M_PhysicMap[BodyIterator];
				C_Static_Render* Static = (C_Static_Render*)entity->GetComponent("Render");
				Static->Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
				Static->Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


			
			}
			
		}
		else if (BodyIterator->GetType() == b2_staticBody) 
		{
			Engine::Entity* entity = S_EntityManager->M_PhysicMap[BodyIterator];
			C_Static_Render* Static = (C_Static_Render*)entity->GetComponent("Render");
			Static->Sprite.setPosition(SCALE * BodyIterator->GetPosition().x, SCALE * BodyIterator->GetPosition().y);
			Static->Sprite.setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
		}
	}


}

void Game::S_ActionTrigger(std::string ActionName)
{
	C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(S_EntityManager->M_EntityMap["Player"][0]->GetComponent("Transform"));
	if (ActionName == "Forward") {
		_SceneManager->_GameManager->View.move(0.f,-viewspeed * _SceneManager->_GameManager->DeltaTime );
		PlayerTransform->Direction = sf::Vector2f(0, -viewspeed);
	}
	if (ActionName == "ForwardRelease") {
		PlayerTransform->Direction = sf::Vector2f(0, 0);
	}
	if (ActionName == "Backward") {
		_SceneManager->_GameManager->View.move(0.f, viewspeed * _SceneManager->_GameManager->DeltaTime );
		PlayerTransform->Direction = sf::Vector2f(0, viewspeed);

	}
	if (ActionName == "BackwardRelease") {
		PlayerTransform->Direction = sf::Vector2f(0, 0);
	}
	if (ActionName == "Left") {
		_SceneManager->_GameManager->View.move( -viewspeed * _SceneManager->_GameManager->DeltaTime ,0.f);
		PlayerTransform->Direction = sf::Vector2f(-viewspeed,0);

	}
	if (ActionName == "LeftRelease") {
		PlayerTransform->Direction = sf::Vector2f(0, 0);
	}
	if (ActionName == "Right") {
		_SceneManager->_GameManager->View.move( viewspeed * _SceneManager->_GameManager->DeltaTime , 0.f);
		PlayerTransform->Direction = sf::Vector2f(viewspeed, 0);

	}
	if (ActionName == "RightRelease") {
		PlayerTransform->Direction = sf::Vector2f(0, 0);
	}

	if (ActionName == "RotLeft") {
		PlayerTransform->RotationDirection = -rotationspeed;

	}
	if (ActionName == "RotLeftRelease") {
		PlayerTransform->RotationDirection = 0;
	}
	if (ActionName == "RotRight") {
		PlayerTransform->RotationDirection = rotationspeed;

	}
	if (ActionName == "RotRightRelease") {
		PlayerTransform->RotationDirection = 0;
	}



}

void Game::S_Begin_Play()
{
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	text.setCharacterSize(30);
	text.setPosition(20.f, 20.f);
	text.setString("Coord");


	Gravity = b2Vec2(0, 0);
	World = new b2World(Gravity);


	S_EntityManager->M_TotalEntity = 500; // on veux 500 entite dans le jeu
	S_EntityManager->GenerateEntity();

	Engine::InitEnvironnement(seed,S_EntityManager);
	InitPlanet();
	InitAsteroid();

	Engine::InputAction Forward(Engine::Trigger::KeyDown,"Forward", sf::Keyboard::W);
	Engine::InputAction Backward(Engine::Trigger::KeyDown, "Backward", sf::Keyboard::S);
	Engine::InputAction Left(Engine::Trigger::KeyDown, "Left", sf::Keyboard::Q);
	Engine::InputAction Right(Engine::Trigger::KeyDown, "Right", sf::Keyboard::E);
	Engine::InputAction RotLeft(Engine::Trigger::KeyDown, "RotLeft", sf::Keyboard::A);
	Engine::InputAction RotRight(Engine::Trigger::KeyDown, "RotRight", sf::Keyboard::D);

	Engine::InputAction ForwardRelease(Engine::Trigger::KeyUp, "ForwardRelease", sf::Keyboard::W);
	Engine::InputAction BackwardRelease(Engine::Trigger::KeyUp, "BackwardRelease", sf::Keyboard::S);
	Engine::InputAction LeftRelease(Engine::Trigger::KeyUp, "LeftRelease", sf::Keyboard::Q);
	Engine::InputAction RightRelease(Engine::Trigger::KeyUp, "RightRelease", sf::Keyboard::E);
	Engine::InputAction RotLeftRelease(Engine::Trigger::KeyUp, "RotLeftRelease", sf::Keyboard::A);
	Engine::InputAction RotRightRelease(Engine::Trigger::KeyUp, "RotRightRelease", sf::Keyboard::D);




	RegisterAction(Forward);
	RegisterAction(Backward);
	RegisterAction(Left);
	RegisterAction(Right);
	RegisterAction(RotLeft);
	RegisterAction(RotRight);
	RegisterAction(ForwardRelease);
	RegisterAction(BackwardRelease);
	RegisterAction(LeftRelease);
	RegisterAction(RightRelease);
	RegisterAction(RotLeftRelease);
	RegisterAction(RotRightRelease);






	System_Mouvement_Actif = new S_Mouvement_Actif();
	InitPlayer();


}
void Game::CreateAsteroidPhysic( std::vector<Engine::Entity*> Asteroids)
{
	for (auto entity : Asteroids)
	{
		C_Static_Render* Static = dynamic_cast<C_Static_Render*>(entity->GetComponent("Render"));

		b2BodyDef BodyDef =  b2BodyDef();
		
		BodyDef.position = b2Vec2(Static->Sprite.getPosition().x / SCALE, Static->Sprite.getPosition().y / SCALE);
		BodyDef.type = b2_dynamicBody;
		b2Body* Body = World->CreateBody(&BodyDef);
		S_EntityManager->M_PhysicMap.insert({Body,entity});
		b2CircleShape circle;
		circle.m_p.Set(Static->Sprite.getGlobalBounds().width / 2.f, Static->Sprite.getGlobalBounds().height / 2.f);
		circle.m_radius = 10.f;
		b2FixtureDef FixtureDef;
		FixtureDef.density = 100.f;
		FixtureDef.friction = 0.f;
		FixtureDef.shape = &circle;
		Body->CreateFixture(&FixtureDef);
		
	}
}

void Game::CreatePlanetPhysic(std::vector<Engine::Entity*> Planets)
{
	for (auto entity : Planets)
	{
		C_Animated_Render* AnimatedRender = dynamic_cast<C_Animated_Render*>(entity->GetComponent("Render"));

		b2BodyDef BodyDef = b2BodyDef();

		BodyDef.position = b2Vec2(AnimatedRender->AnimatedSprite.FrameToDraw().getPosition().x / SCALE, AnimatedRender->AnimatedSprite.FrameToDraw().getPosition().y / SCALE);
		BodyDef.type = b2_staticBody;
		b2Body* Body = World->CreateBody(&BodyDef);
		S_EntityManager->M_PhysicMap.insert({ Body,entity }); 
		b2CircleShape circle;
		circle.m_p.Set(AnimatedRender->AnimatedSprite.FrameToDraw().getGlobalBounds().width / 2.f, AnimatedRender->AnimatedSprite.FrameToDraw().getGlobalBounds().height / 2.f);
		circle.m_radius = 100.f;
		b2FixtureDef FixtureDef;
		FixtureDef.density = 100.f;
		FixtureDef.friction = 0.f;
		FixtureDef.shape = &circle;
		Body->CreateFixture(&FixtureDef);

	}
}

void Game::GenerateUI()
{

}


void Game::S_Input_Mouse(sf::Event event)
{
}

void Game::S_Input_Text(sf::Event event)
{
}

void Game::UpdateEntity()
{

	auto EntitiesRender = S_EntityManager->GetAllEntityWithComponent("Render");
	for (auto Entity : EntitiesRender)
	{
		C_Animated_Render* CheckAnimatation = dynamic_cast<C_Animated_Render*>(Entity->GetComponent("Render"));
		if (CheckAnimatation) {
			CheckAnimatation->AnimatedSprite.updateSprites(_SceneManager->_GameManager->DeltaTime); // mais a jour le sprite des animations
		}
	}

	auto Entities = S_EntityManager->GetAllEntityWithComponent("Mouvement");
	for (auto Entity : Entities)
	{
		C_MouvementActif* CheckMovement = dynamic_cast<C_MouvementActif*>(Entity->GetComponent("Mouvement"));
		if (CheckMovement) {
			C_Static_Render* Static = dynamic_cast<C_Static_Render*>(Entity->GetComponent("Render"));
			C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(Entity->GetComponent("Transform"));
			System_Mouvement_Actif->RunSystem(Entity, _SceneManager->_GameManager->DeltaTime);
		}
	}
	CheckPlayerLimit(S_EntityManager->M_EntityMap["Player"][0]);

	C_Static_Render* Static = dynamic_cast<C_Static_Render*>(S_EntityManager->M_EntityMap["Player"][0]->GetComponent("Render"));
	if (Static) {


		_SceneManager->_GameManager->View.setCenter(Static->Sprite.getPosition());
	}
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
	
	
	

	auto PlanetEntity = S_EntityManager->M_EntityMap["Planet"];

	for (size_t i = 0; i < PlanetEntity.size(); i++)
	{
		PlanetEntity[i]->AddComponent("Render", new C_Animated_Render());
		PlanetEntity[i]->AddComponent("Collider", new C_Static_Collider_Sphere());

		C_Animated_Render* PlanetRender = dynamic_cast<C_Animated_Render*>(PlanetEntity[i]->GetComponent("Render"));
		srand(seed  + i );
		int randomplanet = rand() % AvailablePlanet.size() + 0;
		std::cout << randomplanet;
		PlanetRender->AnimatedSprite.SetupAnimation(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailablePlanet[randomplanet]), 15 / 60.f, {10,1}, sf::Vector2f(0.f, 0.f));
		float randomx = rand() % (int)MapSize.x + -MapSize.x;
		float randomy = rand() % (int)MapSize.y + -MapSize.y;
		PlanetRender->AnimatedSprite.MoveSprite(sf::Vector2f(randomx, randomy));

	}

	CreatePlanetPhysic(S_EntityManager->M_EntityMap["Planet"]);
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
	

	
	
	auto AsteroidEntity = S_EntityManager->M_EntityMap["Asteroid"];

	for (size_t i = 0; i < AsteroidEntity.size(); i++)
	{
		
		AsteroidEntity[i]->AddComponent("Render", new C_Static_Render());
		AsteroidEntity[i]->AddComponent("Collider", new C_Static_Collider_Sphere());
		
		C_Static_Render* AsteroidRender = dynamic_cast<C_Static_Render*>(AsteroidEntity[i]->GetComponent("Render"));
		srand(seed / 2 + i);
		int randomasteroid = rand() % AvailableAsteroid.size() + 0; // selection texture
		float randomx = rand() % (int)MapSize.x + -MapSize.x;
		float randomy = rand() % (int)MapSize.y + -MapSize.y;
		float randomscale = rand() % 1 + 0.3;
		AsteroidRender->Sprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailableAsteroid[randomasteroid]));
		AsteroidRender->Sprite.setOrigin(AsteroidRender->Sprite.getGlobalBounds().width / 2.f, AsteroidRender->Sprite.getGlobalBounds().height / 2.f);
		AsteroidRender->Sprite.setScale(sf::Vector2f(randomscale, randomscale));
		AsteroidRender->Sprite.setPosition(_SceneManager->_GameManager->View.getCenter());
		AsteroidRender->Sprite.move(sf::Vector2f(randomx, randomy));

	}
	CreateAsteroidPhysic(S_EntityManager->M_EntityMap["Asteroid"]);

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
	Render->Sprite.setOrigin(Render->Sprite.getLocalBounds().width / 2.f, Render->Sprite.getLocalBounds().height / 2.f);
	Render->Sprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	std::cout <<"Default X : " << _SceneManager->_GameManager->View.getCenter().x << " Y : " <<_SceneManager->_GameManager->View.getCenter().y << std::endl;




}

void Game::CheckPlayerLimit(Engine::Entity* entity)
{

	C_Static_Render* Render = dynamic_cast<C_Static_Render*>(entity->GetComponent("Render"));

	if (Render->Sprite.getPosition().x > MapSize.x - 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(-MapSize.x + 5 , Render->Sprite.getPosition().y));
		return;
	}
	if (Render->Sprite.getPosition().x < -MapSize.x + 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(MapSize.x - 5, Render->Sprite.getPosition().y));
		return;

	}

	if (Render->Sprite.getPosition().y < -MapSize.y + 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(Render->Sprite.getPosition().x, MapSize.y - 5));
		return;

	}
	if (Render->Sprite.getPosition().y > MapSize.y - 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(Render->Sprite.getPosition().x, -MapSize.y + 5));
		return;

	}



}
