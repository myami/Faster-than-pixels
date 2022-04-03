#pragma once

#include "Engine.h"
#include "box2d/box2d.h"


class FTP_SceneManager;
class S_Mouvement_Actif;
class S_Health;
class S_Shield;

/*! \class Game
* \brief classe enfant de Scene, represente le niveau ou le joueur joue
*
*/
class Game : public Engine::BlankScene {
public:
	Game(std::string name, FTP_SceneManager* refs);
	void S_Syteme() override; // tout les systeme de la scene ( tout les system lie au component)
	void S_Update() override; // debut de frame mais a jour tout se qu il doit mettre a jour 1 /4
	void S_Render() override; // fin de frame affiche le resultat de la simulation 4/4
	void S_Simulation() override; // milieu de frame (box2d) simule tout se qui est dans la scene 3/4
	void S_ActionTrigger(std::string ActionName) override;
	void S_Begin_Play() override;
	void S_Input_Mouse(sf::Event event) override;
	void S_Input_Text(sf::Event event) override;

	void UpdateEntity();


	sf::RectangleShape shape;


	float viewspeed = 200.f;
	float rotationspeed = 2.f;
	int seed = 524524;

	sf::Vector2f MapSize = { 3000.f,3000.f };

	/** Box2d */
	b2Vec2 Gravity;
	b2World* World;
	const int SCALE = 30;


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

	sf::Sprite RepairIcon;
	sf::Text MaximumRepair;
	sf::Text CurrentRepair;

	sf::Sprite MineIcon;
	sf::Text MaximumMine;
	sf::Text CurrentMine;

	sf::Sprite MissileIcon; // todo remplacer par une classe qui contient ces 3 element
	sf::Text MaximumMissile;
	sf::Text CurrentMissile;

	sf::Sprite PerforationIcon;
	sf::Text MaximumPerforation;
	sf::Text CurrentPerforation;

	sf::Sprite CadenceIcon;
	sf::Text MaximumCadence;
	sf::Text CurrentCadence;

	sf::Sprite BoostIcon;

	Engine::Slider Health;
	Engine::Slider Shield;
	Engine::Slider Boost;

	// systeme global
	S_Mouvement_Actif* System_Mouvement_Actif;
	S_Health* Health_Manager; 
	S_Shield* Shield_Manager;

	void DamagePlayer(int amount);



};