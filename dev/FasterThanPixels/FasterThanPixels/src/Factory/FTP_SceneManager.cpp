#include "FTP_SceneManager.h"
#include "../Scene/Starting.h"
#include "../Scene/Authentification.h"
#include "../Scene/MainMenu.h"
#include "../Scene/Game.h"
#include "../Scene/GameModeSelection.h"
#include "../Scene/Settings.h"
#include "../Scene/Compendium.h"
#include "../Scene/PlayerProfile.h"


void FTP_SceneManager::Init(std::string FirstScene)
{
	Starting* st =  new Starting("Cinematique",this);
	Authentification* authentification = new Authentification("Authentification", this);
	MainMenu* mainmenu = new MainMenu("MainMenu", this);
	Game* game = new Game("Game", this);
	GameModeSelection* gms = new GameModeSelection("GameModeSelection", this);
	Settings* settings = new Settings("Settings", this);
	Compendium* compendium = new Compendium("Compendium", this);
	PlayerProfile* profile = new PlayerProfile("PlayerProfile", this);



	AddScene(st);
	AddScene(authentification);
	AddScene(mainmenu);
	AddScene(game);
	AddScene(gms);
	AddScene(settings);
	AddScene(compendium);
	AddScene(profile);


	CurrentScene = "Settings";

	GetCurrentScene()->S_Begin_Play();



}

FTP_SceneManager::FTP_SceneManager(Engine::GameManager* gm)
	:SceneManager(gm)
{

}
