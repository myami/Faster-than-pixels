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
#include "../ECS/Components/C_Health.h"
#include "../ECS/Components/C_Shield.h"


#include "../ECS/System/S_MouvementActif.h"
#include "../ECS/System/S_Health.h"
#include "../ECS/System/S_Shield.h"


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
	S_EntityManager->Update(); // mais a jour la waiting list
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
	if (EntityToDraw.size() != 0) {
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
	}


	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	// render ui
	_SceneManager->_GameManager->Windows->draw(text);
	_SceneManager->_GameManager->Windows->draw(BottomBackground);
	_SceneManager->_GameManager->Windows->draw(LeftBackground);

	_SceneManager->_GameManager->Windows->draw(Repair.GetIcon());
	_SceneManager->_GameManager->Windows->draw(Repair.GetCurrentValue());
	_SceneManager->_GameManager->Windows->draw(Repair.GetMaxValue());

	_SceneManager->_GameManager->Windows->draw(MineIcon);
	_SceneManager->_GameManager->Windows->draw(CurrentMine);
	_SceneManager->_GameManager->Windows->draw(MaximumMine);

	_SceneManager->_GameManager->Windows->draw(MissileIcon);
	_SceneManager->_GameManager->Windows->draw(CurrentMissile);
	_SceneManager->_GameManager->Windows->draw(MaximumMissile);

	_SceneManager->_GameManager->Windows->draw(PerforationIcon);
	_SceneManager->_GameManager->Windows->draw(CurrentPerforation);
	_SceneManager->_GameManager->Windows->draw(MaximumPerforation);

	_SceneManager->_GameManager->Windows->draw(CadenceIcon);
	_SceneManager->_GameManager->Windows->draw(CurrentCadence);
	_SceneManager->_GameManager->Windows->draw(MaximumCadence);

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
	C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(S_EntityManager->GetPlayer()->GetComponent("Transform"));
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
	if (ActionName == "Turbo") {
	}	
	if (ActionName == "TurboRelease") {
	}
	if (ActionName == "Shoot") {
		SpawnLaser(S_EntityManager->GetPlayer());
	}
	if (ActionName == "ShootRelease") {
	}
	if (ActionName == "Mines") {
	}
	if (ActionName == "MinesRelease") {
	}
	if (ActionName == "Missiles") {
	}
	if (ActionName == "MissilesRelease") {
	}
	if (ActionName == "Reparation") {
	}
	if (ActionName == "ReparationRelease") {
	}
	if (ActionName == "Perforation") {
	}
	if (ActionName == "PerforationRelease") {
	}
	if (ActionName == "Surfrequencage") {
	}
	if (ActionName == "SurfrequencageRelease") {
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

	InitPlanet();
	InitAsteroid();

	Engine::InputAction Forward(Engine::Trigger::KeyDown,"Forward", sf::Keyboard::W);
	Engine::InputAction Backward(Engine::Trigger::KeyDown, "Backward", sf::Keyboard::S);
	Engine::InputAction Left(Engine::Trigger::KeyDown, "Left", sf::Keyboard::Q);
	Engine::InputAction Right(Engine::Trigger::KeyDown, "Right", sf::Keyboard::E);
	Engine::InputAction RotLeft(Engine::Trigger::KeyDown, "RotLeft", sf::Keyboard::A);
	Engine::InputAction RotRight(Engine::Trigger::KeyDown, "RotRight", sf::Keyboard::D);
	Engine::InputAction Turbo(Engine::Trigger::KeyDown, "Turbo", sf::Keyboard::LShift);
	Engine::InputAction Shoot(Engine::Trigger::KeyDown, "Shoot", sf::Keyboard::Space);
	Engine::InputAction Mines(Engine::Trigger::KeyDown, "Mines", sf::Keyboard::LControl);
	Engine::InputAction Missiles(Engine::Trigger::KeyDown, "Missiles", sf::Keyboard::F);
	Engine::InputAction Reparation(Engine::Trigger::KeyDown, "Reparation", sf::Keyboard::Num1);
	Engine::InputAction Perforation(Engine::Trigger::KeyDown, "Perforation", sf::Keyboard::Num2);
	Engine::InputAction Surfrequencage(Engine::Trigger::KeyDown, "Surfrequencage", sf::Keyboard::Num3);








	Engine::InputAction ForwardRelease(Engine::Trigger::KeyUp, "ForwardRelease", sf::Keyboard::W);
	Engine::InputAction BackwardRelease(Engine::Trigger::KeyUp, "BackwardRelease", sf::Keyboard::S);
	Engine::InputAction LeftRelease(Engine::Trigger::KeyUp, "LeftRelease", sf::Keyboard::Q);
	Engine::InputAction RightRelease(Engine::Trigger::KeyUp, "RightRelease", sf::Keyboard::E);
	Engine::InputAction RotLeftRelease(Engine::Trigger::KeyUp, "RotLeftRelease", sf::Keyboard::A);
	Engine::InputAction RotRightRelease(Engine::Trigger::KeyUp, "RotRightRelease", sf::Keyboard::D);
	Engine::InputAction TurboRelease(Engine::Trigger::KeyUp, "TurboRelease", sf::Keyboard::LShift);
	Engine::InputAction ShootRelease(Engine::Trigger::KeyUp, "ShootRelease", sf::Keyboard::Space);
	Engine::InputAction MinesRelease(Engine::Trigger::KeyUp, "MinesRelease", sf::Keyboard::LControl);
	Engine::InputAction MissilesRelease(Engine::Trigger::KeyUp, "MissilesRelease", sf::Keyboard::F);
	Engine::InputAction ReparationRelease(Engine::Trigger::KeyUp, "ReparationRelease", sf::Keyboard::Num1);
	Engine::InputAction PerforationRelease(Engine::Trigger::KeyUp, "PerforationRelease", sf::Keyboard::Num2);
	Engine::InputAction SurfrequencageRelease(Engine::Trigger::KeyUp, "SurfrequencageRelease", sf::Keyboard::Num3);










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

	RegisterAction(Turbo);
	RegisterAction(Shoot);
	RegisterAction(Mines);
	RegisterAction(Missiles);
	RegisterAction(Reparation);
	RegisterAction(Perforation);
	RegisterAction(Surfrequencage);
	RegisterAction(TurboRelease);
	RegisterAction(ShootRelease);
	RegisterAction(MinesRelease);
	RegisterAction(MissilesRelease);
	RegisterAction(ReparationRelease);
	RegisterAction(PerforationRelease);
	RegisterAction(SurfrequencageRelease);







	System_Mouvement_Actif = new S_Mouvement_Actif();
	InitPlayer();

	GenerateUI();

	Health_Manager = new S_Health();
	Shield_Manager = new S_Shield();


}
void Game::CreateAsteroidPhysic( std::vector<Engine::Entity*> Asteroids)
{
	for (auto entity : Asteroids)
	{
		C_Static_Render* Static = dynamic_cast<C_Static_Render*>(entity->GetComponent("Render"));

		b2BodyDef BodyDef =  b2BodyDef();
		srand(seed / 4 + entity->E_Id);
		float randomx = rand() % (int)-15 + 15;
		float randomy = rand() % (int)-15 + 15;
		randomx = 0;
		randomy = 0;
		BodyDef.position = b2Vec2(Static->Sprite.getPosition().x / SCALE, Static->Sprite.getPosition().y / SCALE);
		BodyDef.type = b2_dynamicBody;
		BodyDef.linearVelocity = b2Vec2(randomx, randomy);
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
	BottomBackground.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("BottomBackground"));
	BottomBackground.setOrigin(BottomBackground.getGlobalBounds().width / 2.f, BottomBackground.getGlobalBounds().height / 2.f);
	BottomBackground.setPosition(30,_SceneManager->_GameManager->View.getCenter().y +150);

	LeftBackground.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("LeftBackground"));
	LeftBackground.setOrigin(LeftBackground.getGlobalBounds().width / 2.f, LeftBackground.getGlobalBounds().height / 2.f);
	LeftBackground.setPosition(450, _SceneManager->_GameManager->View.getCenter().y + 450);

	Repair.InitHudBonus(_SceneManager->_GameManager->G_AssetManager->GetTexture("RepairIcon"), "3", "0", _SceneManager->_GameManager->G_AssetManager->GetFont("FontText"), 20, sf::Vector2f(100, _SceneManager->_GameManager->View.getCenter().y + 440));

	//RepairIcon.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("RepairIcon"));
	//RepairIcon.setOrigin(RepairIcon.getGlobalBounds().width / 2.f, RepairIcon.getGlobalBounds().height / 2.f);
	//RepairIcon.setPosition(100, _SceneManager->_GameManager->View.getCenter().y +440);

	//CurrentRepair.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	//CurrentRepair.setCharacterSize(20);
	//CurrentRepair.setOrigin(CurrentRepair.getGlobalBounds().width / 2.f, CurrentRepair.getGlobalBounds().height / 2.f);
	//CurrentRepair.setPosition(130, _SceneManager->_GameManager->View.getCenter().y + 430);
	//CurrentRepair.setString("0");

	//MaximumRepair.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	//MaximumRepair.setCharacterSize(20);
	//MaximumRepair.setOrigin(MaximumRepair.getGlobalBounds().width / 2.f, MaximumRepair.getGlobalBounds().height / 2.f);
	//MaximumRepair.setPosition(150, _SceneManager->_GameManager->View.getCenter().y + 430);
	//MaximumRepair.setString("/ 3");

	MineIcon.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MineIcon"));
	MineIcon.setOrigin(MineIcon.getGlobalBounds().width / 2.f, MineIcon.getGlobalBounds().height / 2.f);
	MineIcon.setPosition(210, _SceneManager->_GameManager->View.getCenter().y + 440);

	CurrentMine.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	CurrentMine.setCharacterSize(20);
	CurrentMine.setOrigin(CurrentMine.getGlobalBounds().width / 2.f, CurrentMine.getGlobalBounds().height / 2.f);
	CurrentMine.setPosition(240, _SceneManager->_GameManager->View.getCenter().y + 430);
	CurrentMine.setString("0");

	MaximumMine.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MaximumMine.setCharacterSize(20);
	MaximumMine.setOrigin(MaximumMine.getGlobalBounds().width / 2.f, MaximumMine.getGlobalBounds().height / 2.f);
	MaximumMine.setPosition(260, _SceneManager->_GameManager->View.getCenter().y + 430);
	MaximumMine.setString("/ 3");

	MissileIcon.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MissilesIcon"));
	MissileIcon.setOrigin(MissileIcon.getGlobalBounds().width / 2.f, MissileIcon.getGlobalBounds().height / 2.f);
	MissileIcon.setPosition(330, _SceneManager->_GameManager->View.getCenter().y + 440);

	CurrentMissile.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	CurrentMissile.setCharacterSize(20);
	CurrentMissile.setOrigin(CurrentMissile.getGlobalBounds().width / 2.f, CurrentMissile.getGlobalBounds().height / 2.f);
	CurrentMissile.setPosition(350, _SceneManager->_GameManager->View.getCenter().y + 430);
	CurrentMissile.setString("0");

	MaximumMissile.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MaximumMissile.setCharacterSize(20);
	MaximumMissile.setOrigin(MaximumMissile.getGlobalBounds().width / 2.f, MaximumMissile.getGlobalBounds().height / 2.f);
	MaximumMissile.setPosition(370, _SceneManager->_GameManager->View.getCenter().y + 430);
	MaximumMissile.setString("/ 3");

	PerforationIcon.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("PerforingIcon"));
	PerforationIcon.setOrigin(PerforationIcon.getGlobalBounds().width / 2.f, PerforationIcon.getGlobalBounds().height / 2.f);
	PerforationIcon.setPosition(430, _SceneManager->_GameManager->View.getCenter().y + 440);

	CurrentPerforation.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	CurrentPerforation.setCharacterSize(20);
	CurrentPerforation.setOrigin(CurrentPerforation.getGlobalBounds().width / 2.f, CurrentPerforation.getGlobalBounds().height / 2.f);
	CurrentPerforation.setPosition(450, _SceneManager->_GameManager->View.getCenter().y + 430);
	CurrentPerforation.setString("0");

	MaximumPerforation.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MaximumPerforation.setCharacterSize(20);
	MaximumPerforation.setOrigin(MaximumPerforation.getGlobalBounds().width / 2.f, MaximumPerforation.getGlobalBounds().height / 2.f);
	MaximumPerforation.setPosition(470, _SceneManager->_GameManager->View.getCenter().y + 430);
	MaximumPerforation.setString("/ 3");


	CadenceIcon.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("CadenceIcon"));
	CadenceIcon.setOrigin(CadenceIcon.getGlobalBounds().width / 2.f, CadenceIcon.getGlobalBounds().height / 2.f);
	CadenceIcon.setPosition(530, _SceneManager->_GameManager->View.getCenter().y + 440);

	CurrentCadence.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	CurrentCadence.setCharacterSize(20);
	CurrentCadence.setOrigin(CurrentCadence.getGlobalBounds().width / 2.f, CurrentCadence.getGlobalBounds().height / 2.f);
	CurrentCadence.setPosition(550, _SceneManager->_GameManager->View.getCenter().y + 430);
	CurrentCadence.setString("0");

	MaximumCadence.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	MaximumCadence.setCharacterSize(20);
	MaximumCadence.setOrigin(MaximumCadence.getGlobalBounds().width / 2.f, MaximumCadence.getGlobalBounds().height / 2.f);
	MaximumCadence.setPosition(570, _SceneManager->_GameManager->View.getCenter().y + 430);
	MaximumCadence.setString("/ 3");

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

void Game::DamagePlayer(int amount)
{
	if (!Shield_Manager->AsShield(S_EntityManager->GetPlayer()))
	{
		Health_Manager->DoDamage(amount, S_EntityManager->GetPlayer());
		Health.SetSlider(Health_Manager->GetHealth(S_EntityManager->GetPlayer()));
	}
	else {
		Shield_Manager->DamageShield(amount, S_EntityManager->GetPlayer());
		Shield.SetSlider(Shield_Manager->GetShield(S_EntityManager->GetPlayer()));
	}
}

void Game::SpawnLaser(Engine::Entity* Shooter)
{

	Engine::S_Delay_Entity Laser;
	Laser.E_State = Engine::EntityState::Add;
	Laser.E_ID = S_EntityManager->RequestEntity();
	Laser.E_Tag = "Laser";
	Laser.IsAnimated = false;
	C_Static_Render* ShooterRender = dynamic_cast<C_Static_Render*>(Shooter->GetComponent("Render"));


	std::map < std::string, Engine::Component*> ComponentLaser;
	ComponentLaser.insert(std::pair<std::string, Engine::Component*>("Render", new C_Static_Render()));
	ComponentLaser.insert(std::pair<std::string, Engine::Component*>("Transform", new C_Transform()));
	ComponentLaser.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Static_Collider_Sphere()));
	Laser.E_Component = ComponentLaser;

	C_Static_Render* LaserRender = dynamic_cast<C_Static_Render*>(ComponentLaser["Render"]);
	LaserRender->Sprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("WeaponLaser"));
	LaserRender->Sprite.setOrigin(LaserRender->Sprite.getGlobalBounds().width / 2.f, LaserRender->Sprite.getGlobalBounds().height / 2.f);
	LaserRender->Sprite.setPosition(ShooterRender->Sprite.getOrigin().x + 5.f, ShooterRender->Sprite.getOrigin().y);
	LaserRender->Sprite.setRotation(ShooterRender->Sprite.getRotation());
	
	S_EntityManager->AddToWaiting(Laser);
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
	//CheckPlayerLimit(S_EntityManager->GetPlayer());

	C_Static_Render* Static = dynamic_cast<C_Static_Render*>(S_EntityManager->GetPlayer()->GetComponent("Render"));
	if (Static) {


		_SceneManager->_GameManager->View.setCenter(Static->Sprite.getPosition());
	}

	auto EntitieShield = S_EntityManager->GetAllEntityWithComponent("Shield");
	for (auto Entity : EntitieShield) 
	{
		C_Shield* CheckShield = dynamic_cast<C_Shield*>(Entity->GetComponent("Shield"));
		if (CheckShield)
			Shield_Manager->RunSystem(Entity, _SceneManager->_GameManager->DeltaTime);
			Shield.SetSlider(Shield_Manager->GetShield(S_EntityManager->GetPlayer()));

	}

	auto EntitieHealth = S_EntityManager->GetAllEntityWithComponent("Health");
	for (auto Entity : EntitieHealth)
	{
		C_Health* CheckHealth = dynamic_cast<C_Health*>(Entity->GetComponent("Health"));
		if (CheckHealth)
			Health_Manager->RunSystem(Entity, _SceneManager->_GameManager->DeltaTime);

	}

}

void Game::S_Static_Physic(b2Body* body)
{
	Engine::Entity* entity = S_EntityManager->M_PhysicMap[body];
	C_Static_Render* Static = (C_Static_Render*)entity->GetComponent("Render");
	Static->Sprite.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
	Static->Sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Game::S_Dynamic_Physic(b2Body* body)
{
	Engine::Entity* entity = S_EntityManager->M_PhysicMap[body];
	C_Static_Render* Static = (C_Static_Render*)entity->GetComponent("Render");
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
		Planet.E_ID = S_EntityManager->RequestEntity();
		Planet.E_Tag = "Planet";
		Planet.IsAnimated = true;


		std::map < std::string, Engine::Component*> ComponentPlanet;
		ComponentPlanet.insert(std::pair<std::string, Engine::Component*>("Render", new C_Animated_Render()));
		ComponentPlanet.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Static_Collider_Sphere()));
		Planet.E_Component = ComponentPlanet;

		C_Animated_Render* PlanetRender = dynamic_cast<C_Animated_Render*>(ComponentPlanet["Render"]);
		srand(seed  + i );
		int randomplanet = rand() % AvailablePlanet.size() + 0;
		PlanetRender->AnimatedSprite.SetupAnimation(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailablePlanet[randomplanet]), 15 / 60.f, {10,1}, sf::Vector2f(0.f, 0.f));
		float randomx = rand() % (int)MapSize.x + -MapSize.x;
		float randomy = rand() % (int)MapSize.y + -MapSize.y;

		PlanetRender->AnimatedSprite.MoveSprite(sf::Vector2f(randomx, randomy));


		S_EntityManager->AddToWaiting(Planet);


	}

	CreatePlanetPhysic(S_EntityManager->GetAllEntityWithTag("Planet"));
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

		Asteroid.E_ID = S_EntityManager->RequestEntity();
		Asteroid.E_Tag = "Asteroid";
		Asteroid.IsAnimated = false;


		std::map < std::string, Engine::Component*> ComponentAsteroid;
		ComponentAsteroid.insert(std::pair<std::string, Engine::Component*>("Render", new C_Static_Render()));
		ComponentAsteroid.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Static_Collider_Sphere()));
		Asteroid.E_Component = ComponentAsteroid;


		
		C_Static_Render* AsteroidRender = dynamic_cast<C_Static_Render*>(ComponentAsteroid["Render"]);
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

		S_EntityManager->AddToWaiting(Asteroid);


	}
	CreateAsteroidPhysic(S_EntityManager->GetAllEntityWithTag("Asteroid"));

}

void Game::InitPlayer()
{

	Engine::S_Delay_Entity Player;
	Player.E_ID = S_EntityManager->RequestEntity();
	Player.E_State = Engine::EntityState::Add;
	Player.IsAnimated = false;

	Player.E_Tag = "Player";

	std::map < std::string, Engine::Component*> ComponentPlayer;
	ComponentPlayer.insert(std::pair<std::string, Engine::Component*>("Render", new C_Static_Render()));
	ComponentPlayer.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Kynematic_Collider_Sphere()));
	ComponentPlayer.insert(std::pair<std::string, Engine::Component*>("Transform", new C_Transform()));
	ComponentPlayer.insert(std::pair<std::string, Engine::Component*>("Mouvement", new C_MouvementActif()));
	ComponentPlayer.insert(std::pair<std::string, Engine::Component*>("Health", new C_Health()));
	ComponentPlayer.insert(std::pair<std::string, Engine::Component*>("Shield", new C_Shield()));

	Player.E_Component = ComponentPlayer;

	dynamic_cast<C_Health*>(ComponentPlayer["Health"])->Health = 100;
	dynamic_cast<C_Shield*>(ComponentPlayer["Shield"])->HealthShield = 100;
	dynamic_cast<C_Shield*>(ComponentPlayer["Shield"])->RegenerationAmountPerTick = 10;
	dynamic_cast<C_Shield*>(ComponentPlayer["Shield"])->RegenerationSpeed = 3000;




	C_Static_Render* Render = dynamic_cast<C_Static_Render*>(ComponentPlayer["Render"]);

	Render->Sprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"));
	Render->Sprite.setScale(sf::Vector2f(.2f, .2f));
	Render->Sprite.setOrigin(Render->Sprite.getLocalBounds().width / 2.f, Render->Sprite.getLocalBounds().height / 2.f);
	Render->Sprite.setPosition(_SceneManager->_GameManager->View.getCenter());
	std::cout <<"Default X : " << _SceneManager->_GameManager->View.getCenter().x << " Y : " <<_SceneManager->_GameManager->View.getCenter().y << std::endl;
	/*
	 ajout du player dans la simulation , a decider si ont fais kynematic qui fait un vecteur de velocite ou si il suit un joint ou si on force le kynematic a set position

	b2BodyDef BodyDef = b2BodyDef();

	BodyDef.position = b2Vec2(_SceneManager->_GameManager->View.getCenter().x / SCALE, _SceneManager->_GameManager->View.getCenter().y / SCALE);
	BodyDef.type = b2_kinematicBody;
	b2Body* Body = World->CreateBody(&BodyDef);
	S_EntityManager->M_PhysicMap.insert({ Body,Player });
	b2CircleShape circle;
	circle.m_p.Set(Render->Sprite.getLocalBounds().width / 2.f, Render->Sprite.getLocalBounds().height / 2.f);
	circle.m_radius = 100.f;
	b2FixtureDef FixtureDef;
	FixtureDef.density = 100.f;
	FixtureDef.friction = 0.f;
	FixtureDef.shape = &circle;
	Body->CreateFixture(&FixtureDef);

	*/
	S_EntityManager->AddToWaiting(Player);

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
