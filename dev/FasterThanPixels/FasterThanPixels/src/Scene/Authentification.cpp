#include "Authentification.h"
#include "../Factory/FTP_SceneManager.h"


Authentification::Authentification(std::string name, FTP_SceneManager* refs) :Engine::Scene(name)
{
	_SceneManager = refs;

}

void Authentification::S_Syteme()
{
}

void Authentification::S_Update()
{
}

void Authentification::S_Render()
{
	sf::Sprite Background;
	Background.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("MenuBackground"));
	Background.setOrigin(Background.getGlobalBounds().width / 2.f, Background.getGlobalBounds().height / 2.f);
	Background.setPosition(_SceneManager->_GameManager->View.getCenter());
	_SceneManager->_GameManager->Windows->draw(Background);


}

void Authentification::S_Simulation()
{
}

void Authentification::S_ActionTrigger(std::string ActionName)
{
}

void Authentification::S_Begin_Play()
{
}

void Authentification::S_End_Scene()
{
}

void Authentification::S_Input_Mouse(sf::Event event)
{
}
