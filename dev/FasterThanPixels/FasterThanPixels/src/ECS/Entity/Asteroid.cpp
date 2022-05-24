#include "Asteroid.h"
#include "../Components/C_Static_Render.h"
#include "../Components/C_Static_Collider_Sphere.h"
#include "Engine.h"
#include "../../Scene/Game.h"


Asteroid::Asteroid(Engine::Scene* sc) : Engine::Entity(sc, "Asteroid")
{
}

Asteroid::Asteroid(Engine::Scene* sc, int id) : Engine::Entity(sc, "Asteroid",id)
{
}

void Asteroid::Begin_Play()
{

	AddComponent(new C_Static_Render());
	AddComponent(new C_Static_Collider_Sphere());

	C_Static_Render* AsteroidRender = dynamic_cast<C_Static_Render*>(GetComponent("Render"));
	Game* Scene = dynamic_cast<Game*>(CurrentScene);
	srand(E_Id);
	int randomasteroid = rand() % Scene->AvailableAsteroid.size() + 0; // selection texture
	float randomx = rand() % (int)Scene->MapSize.x + -Scene->MapSize.x;
	float randomy = rand() % (int)Scene->MapSize.y + -Scene->MapSize.y;
	float randomscale = rand() % 1 + 0.3;
	AsteroidRender->Sprite.setTexture(CurrentScene->_SceneManager->_GameManager->G_AssetManager->GetTexture(Scene->AvailableAsteroid[randomasteroid]));
	AsteroidRender->Sprite.setOrigin(AsteroidRender->Sprite.getGlobalBounds().width / 2.f, AsteroidRender->Sprite.getGlobalBounds().height / 2.f);
	AsteroidRender->Sprite.setScale(sf::Vector2f(randomscale, randomscale));
	AsteroidRender->Sprite.setPosition(CurrentScene->_SceneManager->_GameManager->View.getCenter());
	AsteroidRender->Sprite.move(sf::Vector2f(randomx, randomy));
}

void Asteroid::Tick()
{
}

void Asteroid::End_Play()
{
}
