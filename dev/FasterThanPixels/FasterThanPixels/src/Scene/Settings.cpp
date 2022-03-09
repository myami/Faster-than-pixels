#include "Settings.h"
#include "../Factory/FTP_SceneManager.h"

Settings::Settings(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
}


void Settings::S_Render()
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
