#include "Planet.h"

Planet::Planet(): Engine::Entity()
{
	this->E_Tag = "Planet";

}

Planet::Planet(Engine::Scene* sc):Engine::Entity(sc)
{
}

void Planet::Begin_Play()
{

	std::map < std::string, Engine::Component*> ComponentPlanet;
	ComponentPlanet.insert(std::pair<std::string, Engine::Component*>("Render", new C_Animated_Render()));
	ComponentPlanet.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Static_Collider_Sphere()));

	C_Animated_Render* PlanetRender = dynamic_cast<C_Animated_Render*>(ComponentPlanet["Render"]);
	srand(seed + i);
	int randomplanet = rand() % AvailablePlanet.size() + 0;
	PlanetRender->AnimatedSprite.SetupAnimation(_SceneManager->_GameManager->G_AssetManager->GetTexture(AvailablePlanet[randomplanet]), 15 / 60.f, { 10,1 }, sf::Vector2f(0.f, 0.f));
	float randomx = rand() % (int)MapSize.x + -MapSize.x;
	float randomy = rand() % (int)MapSize.y + -MapSize.y;

	PlanetRender->AnimatedSprite.MoveSprite(sf::Vector2f(randomx, randomy));

}

void Planet::Tick()
{
}

void Planet::End_Play()
{
}
