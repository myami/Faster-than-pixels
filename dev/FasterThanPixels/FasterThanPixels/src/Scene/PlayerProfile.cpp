#include "../Factory/FTP_SceneManager.h"
#include "PlayerProfile.h"

PlayerProfile::PlayerProfile(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
}

void PlayerProfile::S_Render()
{
}

void PlayerProfile::S_Begin_Play()
{
}

void PlayerProfile::S_End_Scene()
{
}

void PlayerProfile::S_Input_Mouse(sf::Event event)
{
}
