#include "Game.h"
#include "../Factory/FTP_SceneManager.h"
#include "../Factory/FTP_GameManager.h"
#include "../Factory/FTP_EntityManager.h"
#include <sstream>
#include "../ECS/Components/C_Animated_Render.h"
#include "../ECS/Components/C_Static_Render.h"
#include "../ECS/System/S_MouvementActif.h"
#include "../ECS/System/S_Health.h"
#include "../ECS/System/S_Shield.h"
#include "../ECS/Entity/Player.h"

#include <map>

Game::Game(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
	S_EntityManager = new FTP_EntityManager();
	S_EntityManager->GameManager = _SceneManager->_GameManager;
}

void Game::Tick()
{
	S_EntityManager->Update(); // mais a jour la waiting list
	S_EntityManager->Run_FSM(false); // Appelle le tick de toutes les entite
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(*_SceneManager->_GameManager->Windows);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);
	MousePosView = _SceneManager->_GameManager->Windows->mapPixelToCoords(MousePosWindow);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	std::stringstream ss;
	ss << " Coord \n X : " << MousePosView.x << "\n Y : " << MousePosView.y << "\n";
	text.setString(ss.str());
	System_Mouvement_Actif->RunSystem(_SceneManager->_GameManager->DeltaTime);
}

void Game::S_Render()
{
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);

	// render game

	auto EntityToDraw = S_EntityManager->EntityToDraw();
	if (EntityToDraw.size() != 0) {
		for (auto const& Entity : EntityToDraw)
		{
			if (Entity->E_IsAnimated) {
				C_Animated_Render* CheckAnimatation = dynamic_cast<C_Animated_Render*>(Entity->GetComponent("Render"));
				_SceneManager->_GameManager->Windows->draw(CheckAnimatation->AnimatedSprite.FrameToDraw());
			}
			else {
				Engine::Component* render = Entity->GetComponent("Render");
				C_Static_Render* Static = dynamic_cast<C_Static_Render*>(render);
				if (Static)
					_SceneManager->_GameManager->Windows->draw(Static->Sprite);
			}
		}
	}

	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	// render ui
	_SceneManager->_GameManager->Windows->draw(text);
	_SceneManager->_GameManager->Windows->draw(BottomBackground);
	_SceneManager->_GameManager->Windows->draw(LeftBackground);

	_SceneManager->_GameManager->Windows->draw(Repair.GetIcon());
	_SceneManager->_GameManager->Windows->draw(Repair.GetCurrentValue());
	_SceneManager->_GameManager->Windows->draw(Repair.GetMaxValue());

	_SceneManager->_GameManager->Windows->draw(Mine.GetIcon());
	_SceneManager->_GameManager->Windows->draw(Mine.GetCurrentValue());
	_SceneManager->_GameManager->Windows->draw(Mine.GetMaxValue());

	_SceneManager->_GameManager->Windows->draw(Missile.GetIcon());
	_SceneManager->_GameManager->Windows->draw(Missile.GetCurrentValue());
	_SceneManager->_GameManager->Windows->draw(Missile.GetMaxValue());

	_SceneManager->_GameManager->Windows->draw(Perforation.GetIcon());
	_SceneManager->_GameManager->Windows->draw(Perforation.GetCurrentValue());
	_SceneManager->_GameManager->Windows->draw(Perforation.GetMaxValue());

	_SceneManager->_GameManager->Windows->draw(Cadence.GetIcon());
	_SceneManager->_GameManager->Windows->draw(Cadence.GetCurrentValue());
	_SceneManager->_GameManager->Windows->draw(Cadence.GetMaxValue());

	_SceneManager->_GameManager->Windows->draw(BoostIcon);

	_SceneManager->_GameManager->Windows->draw(Health.Background);
	_SceneManager->_GameManager->Windows->draw(Health.SliderBar);

	_SceneManager->_GameManager->Windows->draw(Shield.Background);
	_SceneManager->_GameManager->Windows->draw(Shield.SliderBar);

	_SceneManager->_GameManager->Windows->draw(Boost.Background);
	_SceneManager->_GameManager->Windows->draw(Boost.SliderBar);

	// center UI on player
}

void Game::S_ActionTrigger(std::string ActionName)
{
	FTP_EntityManager* etm = dynamic_cast<FTP_EntityManager*>(S_EntityManager);
	if (etm) {
		Player* pl = etm->GetPlayer();
		pl->Input(ActionName);
	}
}

void Game::Begin_Play()
{
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	text.setCharacterSize(30);
	text.setPosition(20.f, 20.f);
	text.setString("Coord");

	Gravity = b2Vec2(0, 0);
	World = new b2World(Gravity);

	S_EntityManager->GenerateEntity(this);

	InitPlanet();
	InitAsteroid();

	System_Mouvement_Actif = new S_Mouvement_Actif();
	InitPlayer();

	GenerateUI();

	Health_Manager = new S_Health();
	Shield_Manager = new S_Shield();
	S_EntityManager->Run_FSM(true);
}

void Game::GenerateUI()
{
	BottomBackground.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BottomBackground"));
	BottomBackground.setOrigin(BottomBackground.getGlobalBounds().width / 2.f, BottomBackground.getGlobalBounds().height / 2.f);
	BottomBackground.setPosition(30, _SceneManager->_GameManager->View.getCenter().y + 150);

	LeftBackground.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("LeftBackground"));
	LeftBackground.setOrigin(LeftBackground.getGlobalBounds().width / 2.f, LeftBackground.getGlobalBounds().height / 2.f);
	LeftBackground.setPosition(450, _SceneManager->_GameManager->View.getCenter().y + 450);

	Repair.InitHudBonus(_SceneManager->_GameManager->G_AssetManager->GetTexture("RepairIcon"), "3", "0", _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20, sf::Vector2f(100, _SceneManager->_GameManager->View.getCenter().y + 440));

	Mine.InitHudBonus(_SceneManager->_GameManager->G_AssetManager->GetTexture("MineIcon"), "3", "0", _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20, sf::Vector2f(210, _SceneManager->_GameManager->View.getCenter().y + 440));

	Missile.InitHudBonus(_SceneManager->_GameManager->G_AssetManager->GetTexture("MissilesIcon"), "3", "0", _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20, sf::Vector2f(330, _SceneManager->_GameManager->View.getCenter().y + 440));

	Perforation.InitHudBonus(_SceneManager->_GameManager->G_AssetManager->GetTexture("PerforingIcon"), "3", "0", _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20, sf::Vector2f(430, _SceneManager->_GameManager->View.getCenter().y + 440));

	Cadence.InitHudBonus(_SceneManager->_GameManager->G_AssetManager->GetTexture("CadenceIcon"), "3", "0", _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20, sf::Vector2f(530, _SceneManager->_GameManager->View.getCenter().y + 440));

	BoostIcon.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BoostIcon"));
	BoostIcon.setOrigin(BoostIcon.getGlobalBounds().width / 2.f, BoostIcon.getGlobalBounds().height / 2.f);
	BoostIcon.setPosition(630, _SceneManager->_GameManager->View.getCenter().y + 443);

	Health.Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundHealth"));
	Health.Background.setOrigin(Health.Background.getGlobalBounds().width / 2.f, Health.Background.getGlobalBounds().height / 2.f);
	Health.Background.setPosition(10, _SceneManager->_GameManager->View.getCenter().y + 150);

	Health.SliderBar.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SliderHealth"));
	Health.SliderBar.setOrigin(Health.SliderBar.getGlobalBounds().width / 2.f, Health.SliderBar.getGlobalBounds().height / 2.f);
	Health.SliderBar.setPosition(10, _SceneManager->_GameManager->View.getCenter().y + 150);
	Health.InitSlider(0, 100, 1, true, 100);

	Shield.Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundShield"));
	Shield.Background.setOrigin(Shield.Background.getGlobalBounds().width / 2.f, Shield.Background.getGlobalBounds().height / 2.f);
	Shield.Background.setPosition(40, _SceneManager->_GameManager->View.getCenter().y + 150);

	Shield.SliderBar.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SliderShield"));
	Shield.SliderBar.setOrigin(Shield.SliderBar.getGlobalBounds().width / 2.f, Shield.SliderBar.getGlobalBounds().height / 2.f);
	Shield.SliderBar.setPosition(40, _SceneManager->_GameManager->View.getCenter().y + 150);
	Shield.InitSlider(0, 100, 1, true, 100);

	Boost.Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BackgroundSlider"));
	Boost.Background.setOrigin(Boost.Background.getGlobalBounds().width / 2.f, Boost.Background.getGlobalBounds().height / 2.f);
	Boost.Background.setPosition(750, _SceneManager->_GameManager->View.getCenter().y + 443);

	Boost.SliderBar.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("SliderBoost"));
	Boost.SliderBar.setOrigin(Boost.SliderBar.getGlobalBounds().width / 2.f, Boost.SliderBar.getGlobalBounds().height / 2.f);
	Boost.SliderBar.setPosition(750, _SceneManager->_GameManager->View.getCenter().y + 443);
	Boost.InitSlider(0, 100, 1, false, 100);
}

void Game::SpawnLaser(Engine::Entity* Shooter)
{
	Engine::S_Delay_Entity Laser;
	Laser.E_State = Engine::EntityState::Add;
	Laser.E_ID = S_EntityManager->RequestEntity("Laser");
	Laser.IsAnimated = false;
	S_EntityManager->AddToWaiting(Laser);
}

void Game::S_Input_Mouse(sf::Event event)
{
}

void Game::S_Input_Text(sf::Event event)
{
}

void Game::S_Static_Physic(b2Body* body)
{
	Engine::Entity* entity = S_EntityManager->GetEntityWithId(S_EntityManager->M_PhysicMap[body]);
	C_Static_Render* Static = (C_Static_Render*)entity->GetComponent("Render");
	if (Static)
		Static->Sprite.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
	Static->Sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Game::S_Dynamic_Physic(b2Body* body)
{
	Engine::Entity* entity = S_EntityManager->GetEntityWithId(S_EntityManager->M_PhysicMap[body]);
	C_Static_Render* Static = (C_Static_Render*)entity->GetComponent("Render");
	if (Static)
		Static->Sprite.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
	Static->Sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Game::S_Kynematic_Physic(b2Body* body)
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

	srand(seed / 2);
	int Amount_Planet = rand() % 40 + 15;

	for (size_t i = 0; i < Amount_Planet; i++)
	{
		Engine::S_Delay_Entity Planet;
		Planet.E_State = Engine::EntityState::Add;
		Planet.E_ID = S_EntityManager->RequestEntity("Planet");
		Planet.IsAnimated = true;
		S_EntityManager->AddToWaiting(Planet);
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

	srand(seed / 5);
	int Amount_Asteroid = rand() % 200 + 100;

	for (size_t i = 0; i < Amount_Asteroid; i++)
	{
		Engine::S_Delay_Entity Asteroid;
		Asteroid.E_State = Engine::EntityState::Add;
		Asteroid.E_ID = S_EntityManager->RequestEntity("Asteroid");
		Asteroid.IsAnimated = false;
		S_EntityManager->AddToWaiting(Asteroid);
	}
}

void Game::InitPlayer()
{
	Engine::S_Delay_Entity Player;
	Player.E_ID = S_EntityManager->RequestEntity("Player");
	Player.E_State = Engine::EntityState::Add;
	Player.IsAnimated = false;
	S_EntityManager->AddToWaiting(Player);
}