#include "Starting.h"
#include "../Factory/FTP_SceneManager.h"



Starting::Starting(std::string name, FTP_SceneManager* refs):Engine::BlankScene(name)
{
	this->_SceneManager = refs;
	Engine::InputAction passcinematique;
	passcinematique.Keycode = sf::Keyboard::Space;
	passcinematique.Name = "PasserCinematique";
	passcinematique.TriggerEvent = Engine::Trigger::KeyDown;
	RegisterAction(passcinematique);
}



void Starting::Tick()
{
	if (S_End) {
		_SceneManager->ChangeScene("Authentification");
	}
}

void Starting::S_Render()
{
	sf::Time elapsed1 = clock.getElapsedTime();

	if (elapsed1.asSeconds() > 3 && elapsed1.asSeconds() < 6) 
	{
		_SceneManager->_GameManager->Windows->draw(logo);
	}

	else if (elapsed1.asSeconds() > 6 || pass) { 
		S_End = true;
	}
	else {
		_SceneManager->_GameManager->Windows->draw(text);
	}
	
	
}




void Starting::S_ActionTrigger(std::string ActionName)
{
	if (ActionName == "PasserCinematique") {
		pass = true;
	}
}

void Starting::Begin_Play()
{
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	text.setString("FASTER THAN PIXEL");
	text.setCharacterSize(130);
	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setOrigin(text.getGlobalBounds().width / 2.f, text.getGlobalBounds().height / 2.f);
	text.setPosition(_SceneManager->_GameManager->View.getCenter());


	logo.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("LogoRatatoskr"));
	logo.setOrigin(logo.getGlobalBounds().width / 2.f, logo.getGlobalBounds().height / 2.f);
	logo.setPosition(_SceneManager->_GameManager->View.getCenter());

}

