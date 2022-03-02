#include "Starting.h"
#include "../Factory/FTP_SceneManager.h"



Starting::Starting(std::string name, FTP_SceneManager* refs):Engine::Scene(name)
{
	this->_SceneManager = refs;
	RegisterAction(sf::Keyboard::Space, "PasserCinematique");
}

void Starting::S_Syteme()
{
}

void Starting::S_Update()
{
	// if S_End change de scene
}

void Starting::S_Render()
{
	
	sf::Text text;
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontIntro"));
	text.setString("FASTER THAN PIXEL");
	text.setCharacterSize(130);
	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setOrigin(text.getGlobalBounds().width / 2.f, text.getGlobalBounds().height / 2.f);
	text.setPosition(_SceneManager->_GameManager->View.getCenter());
	

	sf::Sprite logo;
	logo.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("logoratatoskr"));
	logo.setOrigin(logo.getGlobalBounds().width / 2.f, logo.getGlobalBounds().height / 2.f);
	logo.setPosition(_SceneManager->_GameManager->View.getCenter());

	sf::Time elapsed1 = clock.getElapsedTime();

	if (elapsed1.asSeconds() > 3 && elapsed1.asSeconds() < 6) // a bouger dans S_Update et faire un vector de quoi rendre a chaque frame
	{
		_SceneManager->_GameManager->Windows->draw(logo);
	}

	else if (elapsed1.asSeconds() > 6 || pass) { // a bouger dans S_Update je pense
		S_End = true;
	}
	else {
		_SceneManager->_GameManager->Windows->draw(text);
	}
	
	
}



void Starting::S_Simulation()
{
}

void Starting::S_ActionTrigger(std::string ActionName)
{
	if (ActionName == "PasserCinematique") {
		pass = true;
	}
}

void Starting::S_Begin_Play()
{
}

void Starting::S_End_Scene()
{
}



void Starting::S_Action()
{
	for (const auto& action : ActionScene) {
		sf::Keyboard::Key val = static_cast<sf::Keyboard::Key>(action.first); // transforme le int en enum
		if (sf::Keyboard::isKeyPressed(val)) {
			S_ActionTrigger(action.second);
		}
	}
}
