#include "Player.h"
#include "../Components/C_Static_Render.h"
#include "../Components/C_Kynematic_Collider_Sphere.h"
#include "../Components/C_Health.h"
#include "../Components/C_Shield.h"
#include "../Components/C_Transform.h"
#include "../Components/C_Mouvement_Actif.h"
#include "../../Scene/Game.h"
#include "../System/S_MouvementActif.h"

Player::Player(Engine::Scene* sc) : Engine::Entity(sc, "Player")
{
}

Player::Player(Engine::Scene* sc, int id) : Engine::Entity(sc, "Player", id)
{
}

void Player::Begin_Play()
{
	Engine::InputAction Forward(Engine::Trigger::KeyDown, "Forward", sf::Keyboard::W);
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

	CurrentScene->RegisterAction(Forward);
	CurrentScene->RegisterAction(Backward);
	CurrentScene->RegisterAction(Left);
	CurrentScene->RegisterAction(Right);
	CurrentScene->RegisterAction(RotLeft);
	CurrentScene->RegisterAction(RotRight);
	CurrentScene->RegisterAction(ForwardRelease);
	CurrentScene->RegisterAction(BackwardRelease);
	CurrentScene->RegisterAction(LeftRelease);
	CurrentScene->RegisterAction(RightRelease);
	CurrentScene->RegisterAction(RotLeftRelease);
	CurrentScene->RegisterAction(RotRightRelease);

	CurrentScene->RegisterAction(Turbo);
	CurrentScene->RegisterAction(Shoot);
	CurrentScene->RegisterAction(Mines);
	CurrentScene->RegisterAction(Missiles);
	CurrentScene->RegisterAction(Reparation);
	CurrentScene->RegisterAction(Perforation);
	CurrentScene->RegisterAction(Surfrequencage);
	CurrentScene->RegisterAction(TurboRelease);
	CurrentScene->RegisterAction(ShootRelease);
	CurrentScene->RegisterAction(MinesRelease);
	CurrentScene->RegisterAction(MissilesRelease);
	CurrentScene->RegisterAction(ReparationRelease);
	CurrentScene->RegisterAction(PerforationRelease);
	CurrentScene->RegisterAction(SurfrequencageRelease);

	AddComponent(new C_Static_Render());
	AddComponent(new C_Kynematic_Collider_Sphere());
	AddComponent(new C_Transform());
	AddComponent(new C_MouvementActif());
	AddComponent(new C_Health());
	AddComponent(new C_Shield());

	dynamic_cast<C_Health*>(GetComponent("Health"))->Health = 100;
	dynamic_cast<C_Shield*>(GetComponent("Shield"))->HealthShield = 100;
	dynamic_cast<C_Shield*>(GetComponent("Shield"))->RegenerationAmountPerTick = 10;
	dynamic_cast<C_Shield*>(GetComponent("Shield"))->RegenerationSpeed = 3000;

	C_Static_Render* Render = dynamic_cast<C_Static_Render*>(GetComponent("Render"));

	Render->Sprite.setTexture(CurrentScene->_SceneManager->_GameManager->G_AssetManager->GetTexture("Player100"));
	Render->Sprite.setScale(sf::Vector2f(.2f, .2f));
	Render->Sprite.setOrigin(Render->Sprite.getLocalBounds().width / 2.f, Render->Sprite.getLocalBounds().height / 2.f);
	Render->Sprite.setPosition(CurrentScene->_SceneManager->_GameManager->View.getCenter());
	//dynamic_cast<Game*>(CurrentScene)->System_Mouvement_Actif->RegisterSystem(this);
}

void Player::Tick()
{
	CheckLimit();
	C_Static_Render* Render = static_cast<C_Static_Render*>(GetComponent("Render"));

	Render->Sprite.setPosition(CurrentScene->_SceneManager->_GameManager->View.getCenter());

}

void Player::End_Play()
{
}

void Player::Input(std::string ActionName)
{
	Engine::Component* Transform = GetComponent("Transform");
	C_Transform* PlayerTransform = dynamic_cast<C_Transform*>(Transform);
	if (PlayerTransform)
	{
		if (ActionName == "Forward") {
			CurrentScene->_SceneManager->_GameManager->View.move(0.f, -viewspeed * CurrentScene->_SceneManager->_GameManager->DeltaTime);
			PlayerTransform->Direction = sf::Vector2f(0, -viewspeed);
		}
		if (ActionName == "ForwardRelease") {
			PlayerTransform->Direction = sf::Vector2f(0, 0);
		}
		if (ActionName == "Backward") {
			CurrentScene->_SceneManager->_GameManager->View.move(0.f, viewspeed * CurrentScene->_SceneManager->_GameManager->DeltaTime);
			PlayerTransform->Direction = sf::Vector2f(0, viewspeed);
		}
		if (ActionName == "BackwardRelease") {
			PlayerTransform->Direction = sf::Vector2f(0, 0);
		}
		if (ActionName == "Left") {
			CurrentScene->_SceneManager->_GameManager->View.move(-viewspeed * CurrentScene->_SceneManager->_GameManager->DeltaTime, 0.f);
			PlayerTransform->Direction = sf::Vector2f(-viewspeed, 0);
		}
		if (ActionName == "LeftRelease") {
			PlayerTransform->Direction = sf::Vector2f(0, 0);
		}
		if (ActionName == "Right") {
			CurrentScene->_SceneManager->_GameManager->View.move(viewspeed * CurrentScene->_SceneManager->_GameManager->DeltaTime, 0.f);
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
			//CurrentScene->SpawnLaser(S_EntityManager->GetPlayer());
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
	else {
		std::cout << "PATATE" << std::endl;
	}
}

void Player::CheckLimit()
{
	C_Static_Render* Render = dynamic_cast<C_Static_Render*>(GetComponent("Render"));
	Game* Scene = dynamic_cast<Game*>(CurrentScene);

	if (Render->Sprite.getPosition().x > Scene->MapSize.x - 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(-Scene->MapSize.x + 5, Render->Sprite.getPosition().y));
		return;
	}
	if (Render->Sprite.getPosition().x < -Scene->MapSize.x + 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(Scene->MapSize.x - 5, Render->Sprite.getPosition().y));
		return;
	}

	if (Render->Sprite.getPosition().y < -Scene->MapSize.y + 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(Render->Sprite.getPosition().x, Scene->MapSize.y - 5));
		return;
	}
	if (Render->Sprite.getPosition().y > Scene->MapSize.y - 5)
	{
		Render->Sprite.setPosition(sf::Vector2f(Render->Sprite.getPosition().x, -Scene->MapSize.y + 5));
		return;
	}
}

void Player::GetDamage(int amount)
{
	/*
	if (!Shield_Manager->AsShield(S_EntityManager->GetPlayer()))
	{
		Health_Manager->DoDamage(amount, S_EntityManager->GetPlayer());
		Health.SetSlider(Health_Manager->GetHealth(S_EntityManager->GetPlayer()));
	}
	else {
		Shield_Manager->DamageShield(amount, S_EntityManager->GetPlayer());
		Shield.SetSlider(Shield_Manager->GetShield(S_EntityManager->GetPlayer()));
	}
	*/
}