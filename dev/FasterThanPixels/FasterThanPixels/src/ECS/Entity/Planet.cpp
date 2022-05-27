#include "Planet.h"
#include "../../Scene/Game.h"
#include "../Components/C_Animated_Render.h"
#include "../Components/C_Static_Collider_Sphere.h"

Planet::Planet(Engine::Scene* sc) :Engine::Entity(sc, "Planet")
{
}

Planet::Planet(Engine::Scene* sc, int id) : Engine::Entity(sc, "Planet", id)
{
}

void Planet::Begin_Play()
{
	AddComponent(new C_Animated_Render());
	AddComponent(new C_Static_Collider_Sphere());
	C_Animated_Render* PlanetRender = dynamic_cast<C_Animated_Render*>(GetComponent("Render"));
	Game* Scene = dynamic_cast<Game*>(CurrentScene);
	srand(E_Id * 50);
	int randomplanet = rand() % Scene->AvailablePlanet.size() + 0;
	PlanetRender->AnimatedSprite.SetupAnimation(CurrentScene->_SceneManager->_GameManager->G_AssetManager->GetTexture(Scene->AvailablePlanet[randomplanet]), 15 / 60.f, { 10,1 }, CurrentScene->_SceneManager->_GameManager->View.getCenter());
	float randomx = rand() % (int)Scene->MapSize.x + -Scene->MapSize.x;
	srand(E_Id * 20);
	float randomy = rand() % (int)Scene->MapSize.y + -Scene->MapSize.y;
	PlanetRender->AnimatedSprite.MoveSprite(sf::Vector2f(randomx, randomy));
}

void Planet::Tick()
{
	C_Animated_Render* PlanetRender = dynamic_cast<C_Animated_Render*>(GetComponent("Render"));
	PlanetRender->AnimatedSprite.updateSprites(CurrentScene->_SceneManager->_GameManager->DeltaTime);
}

void Planet::End_Play()
{
}