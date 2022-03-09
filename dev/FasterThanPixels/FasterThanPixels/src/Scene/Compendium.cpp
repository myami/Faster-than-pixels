#include "Compendium.h"
#include "../Factory/FTP_SceneManager.h"

Compendium::Compendium(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
}


void Compendium::S_Render()
{
}



void Compendium::S_ActionTrigger(std::string ActionName)
{
}

void Compendium::S_Begin_Play()
{
}

void Compendium::S_End_Scene()
{
}

void Compendium::S_Input_Mouse(sf::Event event)
{
}

void Compendium::S_Input_Text(sf::Event event)
{
}
