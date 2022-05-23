#include "Laser.h"
#include "Engine.h"
Laser::Laser()
{
}

Laser::Laser(Engine::Scene* sc): Engine::Entity(sc)
{
}

void Laser::Begin_Play()
{

	std::map < std::string, Engine::Component*> ComponentLaser;
	ComponentLaser.insert(std::pair<std::string, Engine::Component*>("Render", new C_Static_Render()));
	ComponentLaser.insert(std::pair<std::string, Engine::Component*>("Transform", new C_Transform()));
	ComponentLaser.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Static_Collider_Sphere()));

	C_Static_Render* LaserRender = dynamic_cast<C_Static_Render*>(ComponentLaser["Render"]);
	LaserRender->Sprite.setTexture(CurrentScene->_SceneManager->_GameManager->G_AssetManager->GetTexture("WeaponLaser"));
	LaserRender->Sprite.setOrigin(LaserRender->Sprite.getGlobalBounds().width / 2.f, LaserRender->Sprite.getGlobalBounds().height / 2.f);
	LaserRender->Sprite.setPosition(ShooterRender->Sprite.getPosition().x, ShooterRender->Sprite.getPosition().y - 60.f);
	LaserRender->Sprite.setRotation(ShooterRender->Sprite.getRotation());
}

void Laser::Tick()
{
}

void Laser::End_Play()
{
}
