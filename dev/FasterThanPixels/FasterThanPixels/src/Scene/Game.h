#pragma once

#include "Engine.h"
#include "box2d/box2d.h"

class FTP_SceneManager;
class S_Mouvement_Actif;
class S_Health;
class S_Shield;
class FTP_EntityManager;

/*! \class Game
* \brief classe enfant de Scene, represente le niveau ou le joueur joue
*
*/
class Game : public Engine::BlankScene {
public:
	Game(std::string name, FTP_SceneManager* refs);
	void S_Syteme() override; // tout les systeme de la scene ( tout les system lie au component)
	void S_Update() override;

	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_ActionTrigger(std::string ActionName) override;
	void S_Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;

	void UpdateEntity();
	void S_Static_Physic(b2Body* body) override;
	void S_Dynamic_Physic(b2Body* body) override;
	void S_Kynematic_Physic(b2Body* body) override;

	sf::RectangleShape shape;

	float viewspeed = 200.f;
	float rotationspeed = 2.f;
	int seed = 524524;

	sf::Vector2f MapSize = { 3000.f,3000.f };

	/** Box2d */
	b2Vec2 Gravity;

	sf::Vector2i MousePosScreen;
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;
	sf::Text text;

	void InitPlanet();
	void InitAsteroid();
	void InitPlayer();

	void CheckPlayerLimit(Engine::Entity* entity);
	std::vector<std::string> AvailablePlanet;
	std::vector<std::string> AvailableAsteroid;

	void CreateAsteroidPhysic(std::vector<Engine::Entity*> Asteroids); //https://veendeta.wordpress.com/2012/02/16/tutorial-getting-started-with-box2d/
	void CreatePlanetPhysic(std::vector<Engine::Entity*> Planets);

	void GenerateUI();
	//UI
	sf::Sprite BottomBackground;
	sf::Sprite LeftBackground;

	Engine::Hud_Bonus Repair;
	Engine::Hud_Bonus Mine;
	Engine::Hud_Bonus Missile;
	Engine::Hud_Bonus Perforation;
	Engine::Hud_Bonus Cadence;

	sf::Sprite BoostIcon;

	Engine::Slider Health;
	Engine::Slider Shield;
	Engine::Slider Boost;

	// systeme global
	S_Mouvement_Actif* System_Mouvement_Actif;
	S_Health* Health_Manager;
	S_Shield* Shield_Manager;

	void DamagePlayer(int amount);
	void SpawnLaser(Engine::Entity* Shooter);
};