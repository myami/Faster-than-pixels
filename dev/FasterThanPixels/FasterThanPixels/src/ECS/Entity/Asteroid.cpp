#include "Asteroid.h"
#include "../Components/C_Static_Render.h"
#include "../Components/C_Static_Collider_Sphere.h"
#include "Engine.h"

Asteroid::Asteroid(): Engine::Entity()
{
	this->E_Tag = "Asteroid";

}

Asteroid::Asteroid(Engine::Scene* sc) : Engine::Entity(sc)
{
}

void Asteroid::Begin_Play()
{

	std::map < std::string, Engine::Component*> ComponentAsteroid;
	ComponentAsteroid.insert(std::pair<std::string, Engine::Component*>("Render", new C_Static_Render()));
	ComponentAsteroid.insert(std::pair<std::string, Engine::Component*>("Collider", new C_Static_Collider_Sphere()));

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
}

void Asteroid::Tick()
{
}

void Asteroid::End_Play()
{
}
