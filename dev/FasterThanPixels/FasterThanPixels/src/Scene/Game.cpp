#include "Game.h"
#include "../Factory/FTP_SceneManager.h"
#include <sstream>



Game::Game(std::string name, FTP_SceneManager* refs) : Engine::BlankScene(name)
{
	_SceneManager = refs;
	RegisterAction(sf::Keyboard::W, "Forward");
	RegisterAction(sf::Keyboard::S, "Backward");
	RegisterAction(sf::Keyboard::A, "Left");
	RegisterAction(sf::Keyboard::D, "Right");




}

void Game::S_Syteme()
{
}

void Game::S_Update()
{
	dt = cloackdt.restart().asSeconds();
	MousePosScreen = sf::Mouse::getPosition();
	MousePosWindow = sf::Mouse::getPosition(*_SceneManager->_GameManager->Windows);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);
	MousePosView = _SceneManager->_GameManager->Windows->mapPixelToCoords(MousePosWindow);
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	std::stringstream ss;
	ss << "Screen : " << MousePosScreen.x << " " << MousePosScreen.y << "\n"
		<< " Windows : " << MousePosWindow.x << " " << MousePosWindow.y << "\n"
		<< " View : " << MousePosView.x << " " << MousePosView.y << "\n";

	text.setString(ss.str());
	BlackHole.updateSprites(dt);
}

void Game::S_Render()
{
	_SceneManager->_GameManager->Windows->clear();
	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->View);

	// render game
	_SceneManager->_GameManager->Windows->draw(shape);
	_SceneManager->_GameManager->Windows->draw(testSprite);
	_SceneManager->_GameManager->Windows->draw(BlackHole.FrameToDraw());



	_SceneManager->_GameManager->Windows->setView(_SceneManager->_GameManager->Windows->getDefaultView());

	// render ui
	_SceneManager->_GameManager->Windows->draw(text);


}

void Game::S_Simulation()
{
}

void Game::S_ActionTrigger(std::string ActionName)
{
	if (ActionName == "Forward") {
		_SceneManager->_GameManager->View.move(0.f,-viewspeed * dt * 100);
	}
	if (ActionName == "Backward") {
		_SceneManager->_GameManager->View.move(0.f, viewspeed * dt * 100);
	}
	if (ActionName == "Left") {
		_SceneManager->_GameManager->View.move( -viewspeed * dt * 100,0.f);
	}
	if (ActionName == "Right") {
		_SceneManager->_GameManager->View.move( viewspeed * dt * 100,0.f);
	}
}

void Game::S_Begin_Play()
{
	shape.setSize(sf::Vector2f(100.f, 100.f));
	text.setFont(_SceneManager->_GameManager->G_AssetManager->GetFont("FontText"));
	text.setCharacterSize(30);
	text.setPosition(20.f, 20.f);
	text.setString("TEST");

	testSprite.setTexture(_SceneManager->_GameManager->G_AssetManager->GetTexture("PlayButton"));
	testSprite.setOrigin(testSprite.getGlobalBounds().width / 2.f, testSprite.getGlobalBounds().height / 2.f);
	testSprite.setPosition(-500,0.f);

	BlackHole.SetupAnimation(_SceneManager->_GameManager->G_AssetManager->GetTexture("BlackHole"), 3 / 60.f, { 50,1 },sf::Vector2f(0.f,0.f));

	BlackHole.MoveSprite({ 0,0 });
	BlackHole.ScaleAnimation(3.f);

}



void Game::S_Input_Mouse(sf::Event event)
{
}

void Game::S_Input_Text(sf::Event event)
{
}
