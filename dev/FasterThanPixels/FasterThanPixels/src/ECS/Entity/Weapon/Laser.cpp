#include "Laser.h"
#include "Engine.h"
#include "../../Components/C_Static_Render.h"
#include "../../Components/C_Static_Collider_Sphere.h"
#include "../../Components/C_Transform.h"
Laser::Laser()
{
}

Laser::Laser(Engine::Scene* sc) : Engine::Entity(sc)
{
}

Laser::Laser(Engine::Scene* sc, int id) : Engine::Entity(sc, "Laser", id)
{
}

void Laser::Begin_Play()
{
	AddComponent(new C_Static_Render());
	AddComponent(new C_Transform());
	AddComponent(new C_Static_Collider_Sphere());

	C_Static_Render* LaserRender = dynamic_cast<C_Static_Render*>(GetComponent("Render"));
	LaserRender->Sprite.setTexture(CurrentScene->_SceneManager->_GameManager->G_AssetManager->GetTexture("WeaponLaser"));
	LaserRender->Sprite.setOrigin(LaserRender->Sprite.getGlobalBounds().width / 2.f, LaserRender->Sprite.getGlobalBounds().height / 2.f);
	LaserRender->Sprite.setPosition(LaserRender->Sprite.getPosition().x, LaserRender->Sprite.getPosition().y - 60.f);
	LaserRender->Sprite.setRotation(LaserRender->Sprite.getRotation());
}

void Laser::Tick()
{
}

void Laser::End_Play()
{
}