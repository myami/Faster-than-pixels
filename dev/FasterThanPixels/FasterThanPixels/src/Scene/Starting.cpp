#include "Starting.h"
#include "../Factory/FTP_GameManager.h"

Starting::Starting(std::string name, FTP_GameManager* refs)
{
	this->S_Name = name;
	this->_GameManager = refs;
}

void Starting::S_Syteme()
{
}

void Starting::S_Update()
{
}

void Starting::S_Render()
{
	sf::Text text;
	text.setFont(_GameManager->G_AssetManager->GetFont("FontIntro")); 
	text.setString("FASTER THAN PIXEL");
	text.setCharacterSize(72);
	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	sf::Sprite logo;
	logo.setTexture(_GameManager->G_AssetManager->GetTexture("logoratatoskr"));






	// inside the main loop, between window.clear() and window.display()
	_GameManager->Windows->draw(text);
	_GameManager->Windows->draw(logo);
}

void Starting::S_Action()
{
}

void Starting::S_Simulation()
{
}

void Starting::S_ActionTrigger(Engine::Action& action)
{
}



void Starting::S_Action(Engine::Action& action)
{
}
