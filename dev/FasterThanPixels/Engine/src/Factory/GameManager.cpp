#include "GameManager.h"

void Engine::GameManager::ResizeView(sf::Event event)
{
	float aspectratio = float(Windows->getSize().x / Windows->getSize().y);
	View.setSize(View_Height * aspectratio, View_Height);
}
