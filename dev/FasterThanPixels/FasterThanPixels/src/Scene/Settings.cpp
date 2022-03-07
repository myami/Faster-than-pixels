#include "Settings.h"
#include "../Factory/FTP_SceneManager.h"

Settings::Settings(std::string name, FTP_SceneManager* refs) : Engine::Scene(name)
{
	_SceneManager = refs;
}

void Settings::S_Syteme()
{
}

void Settings::S_Update()
{
}

void Settings::S_Render()
{
}

void Settings::S_Simulation()
{
}

void Settings::S_ActionTrigger(std::string ActionName)
{
}

void Settings::S_Begin_Play()
{
}

void Settings::S_End_Scene()
{
}

void Settings::S_Input_Mouse(sf::Event event)
{
}

void Settings::S_Input_Text(sf::Event event)
{
}
