#include "Profile.h"
#include "../Factory/FTP_SceneManager.h"

Profile::Profile(std::string name, FTP_SceneManager* refs) : Engine::Scene(name)
{
	_SceneManager = refs;
}

void Profile::S_Syteme()
{
}

void Profile::S_Update()
{
}

void Profile::S_Render()
{
}

void Profile::S_Simulation()
{
}

void Profile::S_ActionTrigger(std::string ActionName)
{
}

void Profile::S_Begin_Play()
{
}

void Profile::S_End_Scene()
{
}

void Profile::S_Input_Mouse(sf::Event event)
{
}

void Profile::S_Input_Text(sf::Event event)
{
}
